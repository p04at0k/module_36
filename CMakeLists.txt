cmake_minimum_required(VERSION 3.16)

project(ColorfulCircle)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(CMAKE_INCLUDE_CURRENT_DIR ON)


set(CMAKE_AUTOMOC ON)


find_package(Qt6 COMPONENTS Widgets REQUIRED)


add_executable(ColorfulCircle main.cpp)


target_link_libraries(ColorfulCircle Qt6::Widgets)
