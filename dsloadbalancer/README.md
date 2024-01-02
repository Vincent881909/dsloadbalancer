# dsloadbalancer
Distributed Load Balancer (CPSC416 Capstone Project)

Code can be built using cmake:
$ mkdir -p cmake/build
$ cd cmake/build
$ cmake ../..
$ make

Code can be run using the shell script
./runSystem 100000 3 3

Here the first argument represents the data size you want to test the system against. The second argument represents the number of Storage Nodes you want to spawn. Lastly, the thirf argument represents the number of Worker Nodes you want to use.

You can validate the correctness of the result by running ./validation

