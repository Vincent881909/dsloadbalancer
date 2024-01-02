#ifndef WORKERENODE_H
#define WORKERENODE_H

#include <grpcpp/grpcpp.h>
#include "dsloadbalancer.grpc.pb.h"
#include <string>
#include <unordered_map>

using dsloadbalancer::SystemService;
using dsloadbalancer::KVPair;
using dsloadbalancer::BulkPutResponse;
using dsloadbalancer::BulkGetRequest;
using dsloadbalancer::PingMessage;
using dsloadbalancer::PingResponse;
using dsloadbalancer::TaskInfo;
using dsloadbalancer::Result;

class WorkerNode final : public SystemService::Service {
public:
    WorkerNode(); // Default constructor
    ~WorkerNode(); // Destructor

    // gRPC service methods
    grpc::Status SendPing(grpc::ServerContext* context, const PingMessage* request, PingResponse* response);
    grpc::Status handleTask(grpc::ServerContext* context,::grpc::ServerReader< ::dsloadbalancer::TaskInfo>* reader, Result* response);
    std::unordered_map<int, int> getResult(int minKey, int maxKey, std::string storageIp, std::string storagePort);

    // Accessor methods for IP and port
    std::string GetIpAddress();
    std::string GetPort();
    
    // Evaluate program arguments for IP and port
    void AssignAddress(int argc, char *argv[]); 

private:
    std::string port;
    std::string ipAddress;
    std::string type = "worker";
    std::string applicationPort;
    std::string applicationIp;
};

#endif 