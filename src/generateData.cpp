#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>
#include <ctime>

int main(int argc, char** argv) {
    std::map<int, int> keyValuePairs;
    std::ofstream file("dataset.txt");

    // Seed the random number generator
    std::srand(std::time(nullptr));

    // Create n key-value pairs
    for (int i = 1; i <= std::stoi(argv[argc-1]); ++i) {
        // Generate a random value between 1 and 10
        int value = std::rand() % 10 + 1;
        keyValuePairs[i] = value;
    }

    // Write key-value pairs to file
    if (file.is_open()) {
        for (const auto &pair : keyValuePairs) {
            file << pair.first << "," << pair.second << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file" << std::endl;
        return 1;
    }

    std::cout << "Dataset created successfully." << std::endl;
    return 0;
}
