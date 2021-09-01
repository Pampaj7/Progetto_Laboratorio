cmake_minimum_required(VERSION 3.20)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(SOURCE_FILES ActivitiesTest.cpp RegisterTest.cpp runAllTests.cpp )
add_executable(RunEngagementsTests ${SOURCE_FILES})
target_link_libraries(RunEngagementsTests gtest gtest_main core)