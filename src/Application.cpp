#include "Application.h"
#include <iostream>
#include <vector>
#include <grpcpp/grpcpp.h>
#include "dsloadbalancer.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using grpc::Channel;
using grpc::ClientContext;
using dsloadbalancer::SystemService;
using dsloadbalancer::PingMessage;
using dsloadbalancer::PingResponse;

Application::Application() {} // Default constructor

Application::~Application() {} // Destructor

void Application::sendPings() {

    for (int i=0;i<NodeConfigurations.size();i++) {
        std::string server_address = NodeConfigurations[i].address + ":" + NodeConfigurations[i].port;
        std::shared_ptr<grpc::Channel> channel = grpc::CreateChannel(server_address, grpc::InsecureChannelCredentials());
        std::unique_ptr<SystemService::Stub> stub = SystemService::NewStub(channel);

        std::cout << "Creating Ping request for " << NodeConfigurations[i].address + ":" + NodeConfigurations[i].port << "\n";

        ClientContext context;
        PingMessage request;
        PingResponse response;

        // Set client IP and port
        request.set_ip(address);
        request.set_port(port);

        Status status = stub->SendPing(&context, request, &response);
        if (status.ok() && response.isalive()) {
            std::cout << "Ping success. Server is alive." << std::endl;
            
            // Setting the type of the Node: Storage or Worker Node
            NodeConfigurations[i].type = response.type();
        } else {
            std::cerr << "Ping failed." << std::endl;
        }
    }

};

int Application::getNoOfStorageNodes(){return NoOfStorageNodes;}

int Application::getNoOfWorkerNodes(){return NoOfWorkerNodes;}

std::vector<NodeConfig> Application::getNodeConfig() {return NodeConfigurations;}

void Application::setNoOfStorageNodes(){
    int count = 0;
    for(int i = 0; i < NodeConfigurations.size();i++){if(NodeConfigurations[i].type == "storage"){ count++;}}
    std::cout << "Number of Storage Nodes: " << count << "\n";
    NoOfStorageNodes = count;

};

void Application::setNoOfWorkerNodes(){
    int count = 0;
    for(int i = 0; i < NodeConfigurations.size();i++){if(NodeConfigurations[i].type == "worker"){ count++;}}
    std::cout << "Number of Worker Nodes: " << count << "\n";
    NoOfWorkerNodes = count;
};

void Application::initNodeConfiguration(int argc, char *argv[]){
    int NoOfNodes = (argc - 2)/2;
     std::cout << "Total number of interconnected nodes: " << NoOfNodes << "\n";
    for(int i = 0; i < NoOfNodes;i++){
        NodeConfig node;
        node.address = argv[i+3+i];
        node.port = argv[i+4+i];
        NodeConfigurations.push_back(node);
    }

};

void Application::initAddress(int argc, char *argv[]){
    if(argc < 2){
        std::cout << "Not enough arguments given! Provide Address and Port.\n";
    }

    address = argv[1];
    port = argv[2];
    
    std::cout << "Application Server initialized with " << address << ":" << port << "\n";
}

std::string Application::getIPAdress() {return address;}

std::string Application::getPort() {return port;}


