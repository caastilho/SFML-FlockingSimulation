cmake_minimum_required(VERSION 3.7)
project(FlockSimulation)

# Change output directory to bin
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

# Set C++ version
set (CMAKE_CXX_STANDART 17)


# Create executable 
file (GLOB source_files
    ${CMAKE_SOURCE_DIR}/source/*.cpp;
    ${CMAKE_SOURCE_DIR}/source/engine/*.cpp;
    ${CMAKE_SOURCE_DIR}/source/boids/*.cpp
)

add_executable (app ${source_files})


# Configure 'include' directories 
include_directories (${CMAKE_SOURCE_DIR}/others/include)

# Link SFML libraries
find_package (SFML REQUIRED COMPONENTS graphics)
target_link_libraries (app sfml-graphics)
