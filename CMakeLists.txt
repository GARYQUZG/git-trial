cmake_minimum_required(VERSION 3.10)
project(logger)

set(CMAKE_CXX_STANDARD 11)

# 添加所有的 .cpp 源文件
add_executable(logger 
    main.cpp
    Sources/application_logic.cpp
    Sources/error_handling.cpp
    Sources/logger.cpp
    Sources/memory_manager.cpp
    Sources/pointer_safety.cpp
)
# file(GLOB SOURCES "Sources/*.cpp")
# add_executable(logger ${SOURCES})


# 添加头文件目录
target_include_directories(logger PRIVATE ${PROJECT_SOURCE_DIR}/Headers)

# 连接 pthread 库
find_package(Threads REQUIRED)
target_link_libraries(logger PRIVATE Threads::Threads)
