# dsloadbalancer
Distributed Load Balancer (CPSC416 Capstone Project)

Code can be built using cmake:
$ mkdir -p cmake/build  
$ cd cmake/build  
$ cmake ../..  
$ make  
$ cd ../..  


Code can be run using the provided shell script
./runSystem 100000 4 3

Here, the first argument represents the data size you want to test the system against. In the example above, the program datagen will produce 100000 random key value pairs (Values range between 1-10).
The second argument represents the number of Storage Nodes you want to spawn. Lastly, the third argument represents the number of Worker Nodes you want to use. Once you run the shell script the systemn first stores the dataset across all available Storage Nodes. In thi example above, each Storage Node would store 25000 value pairs. Several SubTasks will be produced and dsitributed across all available Worker Nodes. The worker nodes retrieve the relevenat data and produce a subResult. Once all subResults have been received the program aggregates them to a final result which will be printed. Addtionally, the program times how fast the workers can produce a final result.

You can validate the correctness of the result by running ./validation

(This program uses a simple monolithic architecture to compute the same task.)
Both program will print their results to the terminal. They are both iterating through the dataset produced calculating the most frequent integer.


