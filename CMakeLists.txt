cmake_minimum_required(VERSION 3.13)
project(mexcpp)

# 
# Enable modern C++
# 
set(CMAKE_CXX_STANDARD 17)

# 
# Find packages
# 
find_package(Matlab REQUIRED COMPONENTS MX_LIBRARY MAT_LIBRARY)

#
# mxcpp library
#
add_library(mxcpp INTERFACE)

target_include_directories(mxcpp
    INTERFACE ${PROJECT_SOURCE_DIR}
    INTERFACE ${Matlab_INCLUDE_DIRS}
)

target_link_libraries(mxcpp
    INTERFACE ${Matlab_MX_LIBRARY}
)

#
# matcpp library
#
add_library(matcpp INTERFACE)

target_include_directories(matcpp
    INTERFACE ${PROJECT_SOURCE_DIR}
    INTERFACE ${Matlab_INCLUDE_DIRS}
)

target_link_libraries(matcpp
    INTERFACE ${Matlab_MAT_LIBRARY}
)