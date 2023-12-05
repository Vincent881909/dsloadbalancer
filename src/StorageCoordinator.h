#ifndef STORAGECOORDINATOR_H
#define STORAGECOORDINATOR_H

#include <grpcpp/grpcpp.h>
#include <vector>
#include <tuple>
#include "dsloadbalancer.grpc.pb.h"
#include "Application.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using dsloadbalancer::SystemService;
using dsloadbalancer::PingMessage;
using dsloadbalancer::PingResponse;

typedef std::tuple<int, int> kvPair;

struct NodeDistribution{
    std::string ip;
    std::string port;
    int minKey;
    int maxKey;
};

class StorageCoordinator final : public SystemService::Service {
public:

    int dataSize = 0;
    std::vector<NodeDistribution> dataDistribution;
    StorageCoordinator();
    ~StorageCoordinator();
    void readData();
    void distributeData(std::vector<NodeConfig> NodeConfigurations);
    void initialDataTransfer();

private:
    std::vector<kvPair> data; 
};

#endif 