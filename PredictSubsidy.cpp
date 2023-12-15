//
// Created by Nico Menzi on 15.12.2023.
//
// PredictSubsidy.cpp
#include <iostream>
#include <random>
#include "JSONWriter.cpp" // Include the JSONWriter

int generateMTRandom(unsigned int seed, int range) {
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> dist(1, range);
    return dist(gen);
}

int predictSubsidy(int blockHeight) {
    int rand = generateMTRandom(blockHeight, 1000);

    if (blockHeight < 129600) {
        if (rand >= 990) {
            return 10000;
        } else if (rand >= 940) {
            return 1000;
        } else if (rand >= 840) {
            return 500;
        } else if (rand >= 700) {
            return 250;
        } else if (rand >= 500) {
            return 100;
        } else {
            return 50;
        }
    } else {
        // Add logic for blocks beyond 129600 if necessary
        return 0;
    }
}

int main() {
    JSONWriter jsonWriter;
    std::string filename = "/Users/nico/Documents/block_rewards.json"; // JSON file name
    int currentBlockHeight = 0; // Replace with the actual current block height
    const int numBlocksToShow = 129600;
    std::vector<std::pair<int, int>> blockData;

    for (int i = 0; i < numBlocksToShow; ++i) {
        int nextBlockHeight = currentBlockHeight + i + 1;
        int predictedSubsidy = predictSubsidy(nextBlockHeight);

        blockData.emplace_back(nextBlockHeight, predictedSubsidy);
        std::cout << "Block height " << nextBlockHeight << ": " << predictedSubsidy << std::endl;
    }

    jsonWriter.writeToJson(blockData, filename);
    std::cout << "Data written to " << filename << "." << std::endl;

    return 0;
}
