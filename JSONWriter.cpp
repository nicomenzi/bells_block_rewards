//
// Created by Nico Menzi on 15.12.2023.
//
// JSONWriter.cpp
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <vector>

using json = nlohmann::json;

class JSONWriter {
public:
    void writeToJson(const std::vector<std::pair<int, int>>& blockData, const std::string& filename) {
        json j;
        std::ifstream inFile(filename, std::ios::in);

        // Load existing data if file exists
        if (inFile.good() && inFile.peek() != std::ifstream::traits_type::eof()) {
            inFile >> j;
        }
        inFile.close();

        // Append new data
        for (const auto& [blockHeight, reward] : blockData) {
            j["blocks"].push_back({{"block_height", blockHeight}, {"reward", reward}});
        }

        // Write back to the file in one operation
        std::ofstream outFile(filename, std::ios::out | std::ios::trunc);
        outFile << j.dump(4); // Pretty print with 4 spaces indentation
        outFile.close();
    }
};
