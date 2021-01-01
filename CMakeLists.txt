cmake_minimum_required(VERSION 3.17)
project(Client)

set(CMAKE_CXX_STANDARD 11)

add_executable(Client main.cpp src/readFromKB.cpp include/readFromKB.h src/readFromSock.cpp include/readFromSock.h src/BGRSClient.cpp include/BGRSClient.h)