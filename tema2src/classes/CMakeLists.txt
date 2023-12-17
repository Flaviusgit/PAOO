cmake_minimum_required(VERSION 3.0)

project(myApp VERSION 1.0)

add_library(SmartArray STATIC SmartArray.cpp) -
add_library(SmartInterface STATIC SmartInterface.cpp)
add_library(utils STATIC utils.cpp)
add_library(SecondSmartArray STATIC SecondSmartArray.cpp)
