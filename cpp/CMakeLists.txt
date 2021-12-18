cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(cppJoshi VERSION 0.1.0)

# Include dir
include_directories(/usr/local/include)

# Src
AUX_SOURCE_DIRECTORY(src SRC_FILES)

# Headers
set(PROJECT_SOURCE_DIR "src")
set(PROJECT_INCLUDE_DIR "include/cppJoshi_bits")

# Source files
set(SOURCE_FILES
    ${PROJECT_INCLUDE_DIR}/random.hpp
    ${PROJECT_INCLUDE_DIR}/simpleMC.hpp
    ${PROJECT_INCLUDE_DIR}/payoff.hpp
    ${PROJECT_INCLUDE_DIR}/doubleDigital.hpp
    ${PROJECT_INCLUDE_DIR}/powerOptions.hpp
    ${PROJECT_INCLUDE_DIR}/vanilla.hpp
    ${PROJECT_INCLUDE_DIR}/payoffBridge.hpp
    ${PROJECT_INCLUDE_DIR}/parameters.hpp
    ${PROJECT_INCLUDE_DIR}/mcStatistics.hpp
    ${PROJECT_INCLUDE_DIR}/wrapper.hpp
    ${PROJECT_INCLUDE_DIR}/convergenceTable.hpp
    ${PROJECT_INCLUDE_DIR}/normals.hpp
    ${PROJECT_INCLUDE_DIR}/arrays.hpp
    ${PROJECT_INCLUDE_DIR}/parkMiller.hpp
    ${PROJECT_INCLUDE_DIR}/antiThetic.hpp
    ${PROJECT_INCLUDE_DIR}/pathDependent.hpp
    ${PROJECT_INCLUDE_DIR}/exoticEngine.hpp
    ${PROJECT_INCLUDE_DIR}/exoticBSEngine.hpp
    ${PROJECT_INCLUDE_DIR}/pathDependentAsian.hpp
    ${PROJECT_INCLUDE_DIR}/treeProducts.hpp
    ${PROJECT_INCLUDE_DIR}/treeAmerican.hpp
    ${PROJECT_INCLUDE_DIR}/treeEuropean.hpp
    ${PROJECT_INCLUDE_DIR}/binomialTree.hpp
    ${PROJECT_INCLUDE_DIR}/blackScholesFormulas.hpp
    ${PROJECT_INCLUDE_DIR}/forward.hpp
    

    ${PROJECT_SOURCE_DIR}/random.cpp
    ${PROJECT_SOURCE_DIR}/simpleMC.cpp
    ${PROJECT_SOURCE_DIR}/payoff.cpp
    ${PROJECT_SOURCE_DIR}/doubleDigital.cpp
    ${PROJECT_SOURCE_DIR}/powerOptions.cpp
    ${PROJECT_SOURCE_DIR}/vanilla.cpp
    ${PROJECT_SOURCE_DIR}/payoffBridge.cpp
    ${PROJECT_SOURCE_DIR}/parameters.cpp
    ${PROJECT_SOURCE_DIR}/mcStatistics.cpp
    ${PROJECT_SOURCE_DIR}/convergenceTable.cpp
    ${PROJECT_SOURCE_DIR}/normals.cpp
    ${PROJECT_SOURCE_DIR}/arrays.cpp
    ${PROJECT_SOURCE_DIR}/parkMiller.cpp
    ${PROJECT_SOURCE_DIR}/antiThetic.cpp
    ${PROJECT_SOURCE_DIR}/pathDependent.cpp
    ${PROJECT_SOURCE_DIR}/exoticEngine.cpp
    ${PROJECT_SOURCE_DIR}/exoticBSEngine.cpp
    ${PROJECT_SOURCE_DIR}/pathDependentAsian.cpp
    ${PROJECT_SOURCE_DIR}/treeProducts.cpp
    ${PROJECT_SOURCE_DIR}/treeAmerican.cpp
    ${PROJECT_SOURCE_DIR}/treeEuropean.cpp
    ${PROJECT_SOURCE_DIR}/binomialTree.cpp
    ${PROJECT_SOURCE_DIR}/blackScholesFormulas.cpp
    ${PROJECT_SOURCE_DIR}/forward.cpp
)

# Set up such that XCode organizes the files correctly
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})

# Add library
add_library(cppJoshi SHARED ${SOURCE_FILES})

# Include directories
target_include_directories(cppJoshi PRIVATE include/cppJoshi_bits)

# Install
install(TARGETS cppJoshi DESTINATION lib)

# Install the headers
install(FILES include/cppJoshi DESTINATION include)

# Create base directory
install(DIRECTORY include/cppJoshi_bits DESTINATION include)










