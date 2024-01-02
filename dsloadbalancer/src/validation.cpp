#include <iostream>
#include <fstream>
#include <map>
#include <chrono>

int main() {
    std::ifstream inputFile("dataset.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open the file 'dataset.txt'" << std::endl;
        return 1;
    }

    std::map<int, int> valueCounts;

    int id, value;
    char comma;

    // Record the start time
    auto start = std::chrono::high_resolution_clock::now();

    while (inputFile >> id >> comma >> value) {
        valueCounts[value]++;
    }

    inputFile.close();

    // Record the end time
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the execution time in seconds
    std::chrono::duration<double> duration = end - start;
    double executionTime = duration.count();

    std::cout << "Execution time on a monolithic system: " << executionTime << " seconds" << std::endl;

    int maxCount = 0;
    int mostCommonValue = 0;

    for (const auto& pair : valueCounts) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mostCommonValue = pair.first;
        }
    }

    std::cout << "The most common value is " << mostCommonValue << " with " << maxCount << " occurrences." << std::endl;

    return 0;
}
