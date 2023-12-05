#include "WorkloadCoordinator.h"
#include "StorageCoordinator.h"
#include "Application.h"
#include <string>
#include <tuple>
#include <iostream>
#include <unordered_map>
#include <thread>

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using grpc::Channel;
using grpc::ClientContext;
using dsloadbalancer::SystemService;
using dsloadbalancer::TaskInfo;
using dsloadbalancer::Result;

WorkloadCoordinator::WorkloadCoordinator() {};

WorkloadCoordinator::~WorkloadCoordinator() {};

void WorkloadCoordinator::printFinalResult() {
    int mostFrequentKey = 0;
    int occurences = 0;

    for (const auto& pair : aggregatedResults) {
        if(pair.second > occurences){
            mostFrequentKey = pair.first;
            occurences = pair.second;
        }
    }

    std::cout << "Most frequent element is " << mostFrequentKey << " with " << occurences << " occurences.\n";

}

void WorkloadCoordinator::sendTasks(const std::string& workerPort, const std::vector<Task>& tasksForThisPort) {
    
    std::cout << "Processing tasks for Worker Node with IP address 127.0.0.1: " << workerPort << std::endl;

    grpc::ClientContext context;
    TaskInfo taskInfo;
    Result result;

    std::string server_address = "127.0.0.1:" + workerPort;
    std::shared_ptr<grpc::Channel> channel = grpc::CreateChannel(server_address, grpc::InsecureChannelCredentials());
    std::unique_ptr<SystemService::Stub> stub = SystemService::NewStub(channel);
    std::unique_ptr<grpc::ClientWriter<TaskInfo>> writer(stub->handleTask(&context,&result));

    for (const auto& task : tasksForThisPort) {
        taskInfo.set_datasize(task.dataSize);
        taskInfo.set_minkey(task.minKey);
        taskInfo.set_maxkey(task.maxKey);
        taskInfo.set_workernodeip(task.workerNodeIp);
        taskInfo.set_workernodeport(task.workerNodePort);
        taskInfo.set_storagenodeip(task.storageNodeIp);
        taskInfo.set_storagenodeport(task.storageNodePort);
        writer->Write(taskInfo);
    }

    writer->WritesDone();
    grpc::Status status = writer->Finish();

    if (status.ok()) {
        // Process and print the results
        std::cout << "SubTask processing successful.\n";

        for (const auto& kvpair : result.hashmap()) {
            auto search = aggregatedResults.find(kvpair.key());
            if (search != aggregatedResults.end()) {
                // Key exists, increment its value by kvpair value
                search->second =  search->second + kvpair.value();
            } else {
                // Key not found, insert new key with kvpair value
                aggregatedResults[kvpair.key()] = kvpair.value();
            }
        }

    } else {
        std::cout << "Task processing failed: " << status.error_message() << std::endl;
    }
}

void WorkloadCoordinator::distributeTasks() {
    std::unordered_map<std::string, std::vector<Task>> tasksByWorkerPort;

    // Group tasks by workerNodePort
    for (const auto& task : subTasks) {tasksByWorkerPort[task.workerNodePort].push_back(task);}

    std::vector<std::thread> server_threads;

    // Process tasks for each unique workerNodePort
    for (const auto& pair : tasksByWorkerPort) {
        const std::string& workerPort = pair.first;
        const std::vector<Task>& tasksForThisPort = pair.second;

        // Start the server threads using lambda functions
        server_threads.emplace_back([this, &workerPort, &tasksForThisPort]() {
            this->sendTasks(workerPort, tasksForThisPort);
        });
    
    }

    // Wait for all threads to complete
    for (auto& t : server_threads) {
        if (t.joinable()) {
            t.join();
        }
    }
}

void WorkloadCoordinator::createSubtasks(int noOfWorkerNodes,const std::vector<NodeConfig>& NodeConfigurations,
                                        const std::vector<NodeDistribution>& dataDistribution){

    std::vector<NodeConfig> workerNodes;
    workerNodes.reserve(noOfWorkerNodes);

    for (const auto& nodeConfig : NodeConfigurations) {if (nodeConfig.type == "worker") {workerNodes.push_back(nodeConfig);}}

    int workerNodeIndex = 0;

    for (const auto& storageNode : dataDistribution) {
        int currentMinKey = storageNode.minKey;
        while (currentMinKey <= storageNode.maxKey) {
            int taskSize = std::min(MAX_TASKSIZE, storageNode.maxKey - currentMinKey + 1);
        
            Task task;
            task.dataSize = taskSize;
            task.minKey = currentMinKey;
            task.maxKey = currentMinKey + taskSize - 1;
            task.storageNodeIp = storageNode.ip;
            task.storageNodePort = storageNode.port;

            // Assign to worker node in 'round-robin' fashion
            const auto& workerNode = workerNodes[workerNodeIndex % workerNodes.size()];
            task.workerNodeIp = workerNode.address;
            task.workerNodePort = workerNode.port;
            subTasks.push_back(task);

            currentMinKey += taskSize;
            workerNodeIndex++;
        }
    }
}