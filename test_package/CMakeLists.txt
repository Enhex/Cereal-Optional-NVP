cmake_minimum_required(VERSION 3.15)
project(PackageTest CXX)

find_package(cereal_optional_nvp CONFIG REQUIRED)

add_executable(example example.cpp)
target_link_libraries(example cereal_optional_nvp::cereal_optional_nvp)
