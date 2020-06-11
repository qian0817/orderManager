cmake_minimum_required(VERSION 3.11)
project(orderManager)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

add_executable(orderManager main.cpp Order.cpp Order.hpp OrderManager.hpp List.hpp Node.hpp OrderManager.cpp ui/AddOrderFormDialog.cpp ui/AddOrderFormDialog.h ui/ShowOrderTable.cpp ui/ShowOrderTable.h ui/OrderManagerMainView.cpp ui/OrderManagerMainView.h ui/DeleteAndUpdateDialog.cpp ui/DeleteAndUpdateDialog.h)

target_link_libraries(orderManager Qt5::Core)
target_link_libraries(orderManager Qt5::Widgets)