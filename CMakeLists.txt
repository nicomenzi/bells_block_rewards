cmake_minimum_required(VERSION 3.27)
project(bells_block_rewards)

set(CMAKE_CXX_STANDARD 17)

# Include directory for nlohmann-json
include_directories(/opt/homebrew/Cellar/nlohmann-json/3.11.3/include/)

# Define the executable and source files
add_executable(bells_block_rewards PredictSubsidy.cpp JSONWriter.cpp)
