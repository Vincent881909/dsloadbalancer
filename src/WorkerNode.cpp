#include "WorkerNode.h"
#include <threadPool.h>
#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include <thread>

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using dsloadbalancer::SystemService;
using dsloadbalancer::KVPair;
using dsloadbalancer::BulkPutResponse;
using dsloadbalancer::BulkGetRequest;
using dsloadbalancer::PingMessage;
using dsloadbalancer::PingResponse;

WorkerNode::WorkerNode() {}

WorkerNode::~WorkerNode() {}

std::string WorkerNode::GetIpAddress() {return ipAddress;}

std::string WorkerNode::GetPort() {return port;}

void WorkerNode::AssignAddress(int argc, char *argv[]) {
    if (argc == 3) {
        ipAddress = argv[1];
        port = argv[2];
    } else {
        std::cerr << "Insufficient arguments provided. Need IP address and port." << std::endl;
    }
}

grpc::Status WorkerNode::SendPing(grpc::ServerContext* context, const PingMessage* request, PingResponse* response) {
    std::cout << "Ping Message received at Worker Node " << GetIpAddress() << ":" << GetPort() << "\n";

    applicationIp = request->ip();
    applicationPort = request->port();
    
    response->set_isalive(true);
    response->set_ip(ipAddress);
    response->set_port(port);
    response->set_type(type);

    return grpc::Status::OK;
}

std::unordered_map<int, int> WorkerNode::getResult(int minKey, int maxKey, std::string storageIp, std::string storagePort){
    std::unordered_map<int, int> result;
    std::string server_address = storageIp + ":" + storagePort;
    std::shared_ptr<grpc::Channel> channel = grpc::CreateChannel(server_address, grpc::InsecureChannelCredentials());
    std::unique_ptr<SystemService::Stub> stub = SystemService::NewStub(channel);

    grpc::ClientContext context;
    BulkGetRequest getRequest;
    KVPair kvpair;

    for(int i = minKey; i <= maxKey;i++){getRequest.add_keys(i);}

    std::unique_ptr<grpc::ClientReader<KVPair>> reader(stub->Get(&context, getRequest));

    while (reader->Read(&kvpair)) {
        auto search = result.find(kvpair.value());
        if (search != result.end()) {
            // Key exists, increment its value
            search->second++;
        } else {
            // Key not found, insert new key with value 1
            result[kvpair.value()] = 1;
        }
    }

    Status status = reader->Finish();

    return result;
}

grpc::Status WorkerNode::handleTask(grpc::ServerContext* context,
                        ::grpc::ServerReader< ::dsloadbalancer::TaskInfo>* reader, Result* response){

    dsloadbalancer::TaskInfo task;

    while (reader->Read(&task)) {

        std::unordered_map<int, int> subResult = getResult(task.minkey(),task.maxkey(),task.storagenodeip(),task.storagenodeport());

        for (const auto& KVPair : subResult) {
            auto* pair = response->add_hashmap();
            pair->set_key(KVPair.first);
            pair->set_value(KVPair.second);
        }
    }
    
    return Status::OK;
}

int main(int argc, char** argv) {
    WorkerNode node;
    node.AssignAddress(argc, argv);

    std::string server_address = node.GetIpAddress() + ":" + node.GetPort();

    ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&node);

    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Worker Node Server listening on " << server_address << std::endl;

    server->Wait();

    return 0;
}
