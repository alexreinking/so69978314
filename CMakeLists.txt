# CMakeLists.txt
cmake_minimum_required(VERSION 3.22)
project(so69978314)

if (PROJECT_IS_TOP_LEVEL)
    include(CTest)
endif ()

option(BUILD_SHARED_LIBS "Build shared libraries instead of static libraries" ON)

find_package(tinyxml2 REQUIRED)

add_library(myLib src/myLib.cpp include/myLib.h)
add_library(myLib::myLib ALIAS myLib)
target_link_libraries(myLib PRIVATE tinyxml2::tinyxml2)
target_include_directories(
    myLib PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>")
set_target_properties(myLib PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS YES)

if (BUILD_TESTING)
    find_package(GTest REQUIRED)
    include(GoogleTest)

    add_executable(unittest test/test.cpp)
    target_link_libraries(unittest PRIVATE GTest::gtest GTest::gtest_main myLib::myLib)

    if (WIN32)
        add_custom_command(
            TARGET unittest POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_RUNTIME_DLLS:unittest> $<TARGET_FILE_DIR:unittest>
            COMMAND_EXPAND_LISTS
        )
    endif ()

    gtest_discover_tests(unittest)
endif ()
