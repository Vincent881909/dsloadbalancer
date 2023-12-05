#include "StorageCoordinator.h"
#include "Application.h"
#include <iostream>
#include <fstream>

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using grpc::Channel;
using grpc::ClientContext;
using dsloadbalancer::SystemService;
using dsloadbalancer::KVPair;
using dsloadbalancer::BulkGetRequest;
using dsloadbalancer::BulkPutResponse;


StorageCoordinator::StorageCoordinator() {}; //Default Constructor

StorageCoordinator::~StorageCoordinator() {}; //Destructor

void StorageCoordinator::readData() {
    const std::string &filename = "dataset.txt";
    std::ifstream file(filename);
    std::string line;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            int key, value;
            char comma;

            if (ss >> key >> comma >> value && comma == ',') {
                data.push_back(std::make_tuple(key,value));
                dataSize++;
            }
        }
        file.close();
    } else {
        std::cerr << "Unable to open data set." << std::endl;
    }

    std::cout << "Total data size is: " << dataSize << "\n";

};

void StorageCoordinator::distributeData(std::vector<NodeConfig> NodeConfigurations){

    int NoOfStorageNodes = 0;
    for (const auto& nodeConfig : NodeConfigurations) {if (nodeConfig.type == "storage") {NoOfStorageNodes++;}}

    int baseSize = dataSize / NoOfStorageNodes;  // Base size for each node
    int remainder = dataSize % NoOfStorageNodes; // Extra data to distribute

    int currentStart = 1;
    for (int i = 0; i < NoOfStorageNodes; ++i) {
        NodeDistribution nodeDistribution;
        nodeDistribution.minKey = currentStart;
        nodeDistribution.ip = NodeConfigurations[i].address;
        nodeDistribution.port = NodeConfigurations[i].port;

        // Add an extra data point to the nodes until the remainder is distributed
        nodeDistribution.maxKey = currentStart + baseSize + (i < remainder ? 1 : 0) - 1;
        currentStart = nodeDistribution.maxKey + 1;
        dataDistribution.push_back(nodeDistribution);
    }
     
}

void StorageCoordinator::initialDataTransfer(){
    for(int i = 0; i < dataDistribution.size();i++){
        std::string server_address = dataDistribution[i].ip + ":" + dataDistribution[i].port;
        std::shared_ptr<grpc::Channel> channel = grpc::CreateChannel(server_address, grpc::InsecureChannelCredentials());
        std::unique_ptr<SystemService::Stub> stub = SystemService::NewStub(channel);
        std::cout << "Creating Put request for Storage Node: " << server_address << "\n";

        ClientContext context;
        dsloadbalancer::BulkPutResponse response;
        std::unique_ptr<grpc::ClientWriter<KVPair>> writer(stub->Put(&context, &response));

        for (int j = dataDistribution[i].minKey; j <= dataDistribution[i].maxKey; j++) {
            KVPair kvpair;
            kvpair.set_key(j);
            kvpair.set_value(std::get<1>(data[j-1]));
            writer->Write(kvpair);
        }

        writer->WritesDone();
        Status status = writer->Finish();
        if (status.ok()) {
            std::cout << "Put operation completed successfully." << std::endl;
        } else {
            std::cerr << "Put operation failed." << std::endl;
        }

    }
};