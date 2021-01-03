cmake_minimum_required(VERSION 3.17)
project(Client)

link_libraries("-lboost_system")
link_libraries(-pthread)


set(CMAKE_CXX_STANDARD 11)

add_executable(Client
        src/readFromKB.cpp
        include/readFromKB.h
        src/readFromSock.cpp
        include/readFromSock.h
        src/Client.cpp
        include/Client.h
        include/connectionHandler.h
        src/connectionHandler.cpp)