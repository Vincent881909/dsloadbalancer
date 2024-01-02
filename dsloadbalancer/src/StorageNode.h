#ifndef STORAGENODE_H
#define STORAGENODE_H

#include <string>
#include <unordered_map>
#include <grpcpp/grpcpp.h>
#include "dsloadbalancer.grpc.pb.h"

using dsloadbalancer::SystemService;
using dsloadbalancer::KVPair;
using dsloadbalancer::BulkPutResponse;
using dsloadbalancer::BulkGetRequest;
using dsloadbalancer::PingMessage;
using dsloadbalancer::PingResponse;

class StorageNode final : public SystemService::Service {
public:
    StorageNode(); // Default constructor
    ~StorageNode(); // Destructor

    // gRPC service methods
    grpc::Status Put(grpc::ServerContext* context, ::grpc::ServerReader< ::dsloadbalancer::KVPair>* reader, BulkPutResponse* response) override;
    grpc::Status Get(grpc::ServerContext* context, const BulkGetRequest* request, ::grpc::ServerWriter< ::dsloadbalancer::KVPair>* writer) override;
    grpc::Status SendPing(grpc::ServerContext* context, const PingMessage* request, PingResponse* response) override ;
    
    void AssignAddress(int argc, char *argv[]); // Evaluate program arguments for IP and port

    // Methods to manage the local key-value store
    int LocalGet(int key); 
    void LocalPut(int key, int value); 

    // Accessor methods for IP and port
    std::string GetIpAddress();
    std::string GetPort();

private:
    std::string port;
    std::string ipAddress;
    std::string type = "storage";
    std::unordered_map<int, int> kvStore; 
    std::string applicationPort;
    std::string applicationIp;
    
};

#endif
