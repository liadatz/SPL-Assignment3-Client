cmake_minimum_required(VERSION 3.17)
project(Client)

find_package(Boost 1.58.0 REQUIRED COMPONENTS system filesystem)
target_link_libraries(Client ${Boost_LIBRARIES})

set(CMAKE_CXX_STANDARD 11)

add_executable(Client
        src/readFromKB.cpp
        include/readFromKB.h
        src/readFromSock.cpp
        include/readFromSock.h
        src/Client.cpp
        include/Client.h
        include/connectionHandler.h
        src/connectionHandler.cpp
        )