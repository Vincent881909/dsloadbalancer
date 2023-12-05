#include "StorageNode.h"
#include <grpcpp/grpcpp.h>
#include "dsloadbalancer.grpc.pb.h"
#include <threadPool.h>
#include <iostream>
#include <memory>
#include <string>
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

StorageNode::StorageNode() {}
StorageNode::~StorageNode() {}

// gRPC service methods
grpc::Status StorageNode::Put(grpc::ServerContext* context, grpc::ServerReader<KVPair>* reader, BulkPutResponse* response) {
    KVPair kvpair;
    while (reader->Read(&kvpair)) {
        // Process each KVPair locally
        LocalPut(kvpair.key(), kvpair.value());
    }
    response->set_success(true);
    return grpc::Status::OK;
}

grpc::Status StorageNode::Get(grpc::ServerContext* context, const BulkGetRequest* request, grpc::ServerWriter<KVPair>* writer) {
    for (const int32_t& key : request->keys()) {
        int value = LocalGet(key);
        if (value != -1) {
            KVPair kvpair;
            kvpair.set_key(key);
            kvpair.set_value(value);
            writer->Write(kvpair);
        } 
    }
    return grpc::Status::OK;
}

grpc::Status StorageNode::SendPing(grpc::ServerContext* context, const PingMessage* request, PingResponse* response) {
    std::cout << "Ping Message received at Storage Node " << GetIpAddress() << ":" << GetPort() << "\n";
    applicationIp = request->ip();
    applicationPort = request->port();
    
    response->set_isalive(true);
    response->set_ip(ipAddress);
    response->set_port(port);
    response->set_type(type);

    return grpc::Status::OK;
}

void StorageNode::AssignAddress(int argc, char *argv[]) {
    if (argc == 3) {
        ipAddress = argv[1];
        port = argv[2];
    } else {
        std::cerr << "Insufficient arguments provided. Need IP address and port." << std::endl;
    }
}

int StorageNode::LocalGet(int key) {
    auto search = kvStore.find(key);
    if (search != kvStore.end()) {
        return search->second;
    } else {
        std::cerr << "Key not found." << std::endl;
        return -1;
    }
}

void StorageNode::LocalPut(int key, int value) {
    kvStore[key] = value;
}

std::string StorageNode::GetIpAddress() {return ipAddress;}

std::string StorageNode::GetPort() {return port;}

int main(int argc, char** argv) {
    StorageNode node;
    node.AssignAddress(argc, argv);

    std::string server_address = node.GetIpAddress() + ":" + node.GetPort();
    ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&node);

    std::cout << "Storage Node Server listening on " << server_address << std::endl;

    // Create a thread pool
    const int num_threads = 2;
    std::vector<std::thread> thread_pool;

    for (int i = 0; i < num_threads; ++i) {
        thread_pool.emplace_back([&node, &builder]() {
            // Create a new server instance for each thread to handle concurrent requests
            std::unique_ptr<Server> server(builder.BuildAndStart());
            server->Wait();
        });
    }

    // Wait for all threads in the pool to finish
    for (std::thread& thread : thread_pool) {
        thread.join();
    }

    return 0;
}
