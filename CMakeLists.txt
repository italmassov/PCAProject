cmake_minimum_required(VERSION 3.20)
project(PCAProject)
set(CMAKE_CXX_STANDARD 23)

add_executable(PCAProject 
    main.cpp 
    data_loader.cpp 
    matrix_utils.cpp 
    pca_algorithm.cpp 
    results.cpp)