cmake_minimum_required(VERSION 3.16)
project(orderManager)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_COMPILER clang++)

add_executable(orderManager main.cpp Order.cpp Order.hpp OrderManager.hpp List.hpp Node.hpp OrderManager.cpp utils.hpp utils.cpp)