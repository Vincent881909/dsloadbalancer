# Distributed Load Balancer (dsloadbalancer)

Welcome to the Distributed Load Balancer project! This system is designed as a capstone project for UBC CPSC416 and aims to efficiently distribute and manage workloads across a network of storage and worker nodes.

## Features

- **Dynamic Load Distribution**: The system dynamically distributes data across multiple storage nodes and assigns tasks to worker nodes, ensuring efficient load balancing.
- **gRPC Communication**: Utilizes gRPC for efficient and robust communication between nodes.
- **Scalability**: Easily scale the number of storage and worker nodes to meet the demand.
- **Performance Metrics**: Measures and reports the time taken for the workers to produce the final result, allowing for performance optimization.

## Getting Started

### Prerequisites

- Ensure you have `cmake` installed on your system to build the project.
- The system is built and tested on UNIX-based systems.

### Building the Code

Clone the repository to your local machine. Navigate to the cloned directory and run the following commands:

```bash
$ mkdir -p cmake/build  
$ cd cmake/build  
$ cmake ../..  
$ make  
$ cd ../..  
```

### Running the System

Execute the system using the provided shell script with the desired parameters:

```bash
./runSystem [data_size] [storage_nodes] [worker_nodes]
```

- `data_size`: The number of random key-value pairs to generate and distribute.
- `storage_nodes`: The number of Storage Nodes in the system.
- `worker_nodes`: The number of Worker Nodes in the system.

For example:

```bash
./runSystem 100000 4 3
```

This command runs the system with 100,000 key-value pairs, 4 Storage Nodes, and 3 Worker Nodes.

### Validating Results

To ensure the correctness of the system's output, you can run the validation script:

```bash
./validation
```

This script compares the results produced by the distributed system against a monolithic architecture implementation.

## Documentation

For a deeper understanding of the system's design and implementation, refer to the following documents:

- [System Design](https://github.com/Vincent881909/dsloadbalancer/blob/main/docs/SystemDesign.pdf)
- [Project Reflection](https://github.com/Vincent881909/dsloadbalancer/blob/main/docs/ProjectReflection.pdf)