cmake_minimum_required(VERSION 3.20)
project(Progetto_Laboratorio)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(test)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})


set(SOURCE_FILES Activities.cpp Activities.h Register.cpp Register.h)
add_executable(Progetto_Laboratorio main.cpp)
ADD_LIBRARY(core ${SOURCE_FILES})
target_link_libraries(Progetto_Laboratorio core ${wxWidgets_LIBRARIES})
