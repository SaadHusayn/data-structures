#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <iostream>
#include <fstream>
#include <string>

class Configuration {
    std::string sortingAlgorithm;
    std::string searchingAlgorithm;
    int threshold;

public:
    Configuration(const std::string &filename) {
        std::ifstream configFile(filename);
        if (!configFile.is_open()) {
            std::cerr << "Error opening configuration file!" << std::endl;
            return;
        }

        std::string line;
        while (std::getline(configFile, line)) {
            if (line.find("default_sorting_algorithm=") == 0) {
                sortingAlgorithm = line.substr(29); // Extract value
            } else if (line.find("default_searching_algorithm=") == 0) {
                searchingAlgorithm = line.substr(28); // Extract value
            } else if (line.find("threshold=") == 0) {
                threshold = std::stoi(line.substr(10)); // Extract value
            }
        }

        configFile.close();
    }

    std::string getSortingAlgorithm() const {
        return sortingAlgorithm;
    }

    std::string getSearchingAlgorithm() const {
        return searchingAlgorithm;
    }

    int getThreshold() const {
        return threshold;
    }
};

#endif
