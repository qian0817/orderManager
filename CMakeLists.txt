cmake_minimum_required(VERSION 3.16)
project(orderManager)

set(CMAKE_CXX_STANDARD 11)

add_executable(orderManager main.cpp order.cpp order.hpp order_manager.hpp list.hpp node.hpp order_manager.cpp)