#include <iostream>
#include "Application.h"
#include "Application.cpp"
#include "WorkloadCoordinator.h"
#include "WorkloadCoordinator.cpp"
#include "StorageCoordinator.h"
#include "StorageCoordinator.cpp"
#include <chrono>

int main(int argc, char** argv) {

    std::cout<< "Starting System...\n";

    Application app;
    WorkloadCoordinator workloadCoordinator;
    StorageCoordinator storageCoordinator;

    // Initialize the address and port
    app.initAddress(argc, argv);

    // Initialize the node configuration
    app.initNodeConfiguration(argc, argv);

    // Start the gRPC server
    std::string server_address = app.getIPAdress() + ":" + app.getPort();
    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&app);

    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;

    app.sendPings();

    // Calculate and set the number of storage and worker nodes
    app.setNoOfStorageNodes();
    app.setNoOfWorkerNodes();

    // Handle Data
    std::cout << "Initializing Data Transfer to Storage Nodes...\n";
    storageCoordinator.readData();
    storageCoordinator.distributeData(app.getNodeConfig());
    storageCoordinator.initialDataTransfer();

    workloadCoordinator.createSubtasks(app.getNoOfWorkerNodes(),app.getNodeConfig(),storageCoordinator.dataDistribution);

    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "Distributing Tasks...\n";
    workloadCoordinator.distributeTasks();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    double executionTime = duration.count();

    workloadCoordinator.printFinalResult();

    std::cout << "Execution time on the distributed system: " << executionTime << " seconds" << std::endl;

    return 0;
}