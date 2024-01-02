#ifndef APPLICATION_H
#define APPLICATION_H
#include <vector>
#include <grpcpp/grpcpp.h>
#include "dsloadbalancer.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using dsloadbalancer::SystemService;
using dsloadbalancer::PingMessage;
using dsloadbalancer::PingResponse;

struct NodeConfig {
    std::string address;
    std::string port;
    std::string type;
};

class Application final : public SystemService::Service{
public:
    Application(); // Default constructor
    ~Application(); // Destructor
    void sendPings();
    int getNoOfStorageNodes();
    int getNoOfWorkerNodes();
    std::vector<NodeConfig> getNodeConfig();
    void setNoOfStorageNodes();
    void setNoOfWorkerNodes();
    void initNodeConfiguration(int argc, char *argv[]);
    void initAddress(int argc, char *argv[]);
    std::string getIPAdress();
    std::string getPort();

private:
    std::string address;
    std::string port;
    std::vector<NodeConfig> NodeConfigurations;
    int NoOfStorageNodes;
    int NoOfWorkerNodes;
};

#endif 