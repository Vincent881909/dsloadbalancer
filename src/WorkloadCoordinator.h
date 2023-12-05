#ifndef WORKLOADCOORDINATOR_H
#define WORKLOADCOORDINATOR_H
#define MAX_TASKSIZE 100000 //Max size of data points one task will address

#include <grpcpp/grpcpp.h>
#include "dsloadbalancer.grpc.pb.h"
#include "Application.h"
#include "StorageCoordinator.h"
#include <vector>
#include <string>
#include <tuple>

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using dsloadbalancer::SystemService;
using dsloadbalancer::PingMessage;
using dsloadbalancer::PingResponse;

struct Task {
    int dataSize;
    int minKey;
    int maxKey;
    std::string workerNodeIp;
    std::string workerNodePort;
    std::string storageNodeIp;
    std::string storageNodePort;
};

class WorkloadCoordinator final : public SystemService::Service{

public:
    WorkloadCoordinator();
    ~WorkloadCoordinator();
    void createSubtasks(int noOfWorkerNodes, const std::vector<NodeConfig>& NodeConfigurations,
                        const std::vector<NodeDistribution>& dataDistribution);
    void distributeTasks();
    void printFinalResult();
    void sendTasks(const std::string& workerPort, const std::vector<Task>& tasksForThisPort);

private:
    std::vector<Task> subTasks;
    std::map<int,int> aggregatedResults;
};

#endif 