
#include "../include/BGRSClient.h"
#include <mutex>
#include <thread>


int main(int argc, char *argv[]){
    std::string host = argv[1];
    short port = atoi(argv[2]);
    std::mutex mutex;
    ConnectionHandler handler(host, port);
    bool *shouldTerminate = new bool(false);
    readFromKB task1(1, mutex, handler, shouldTerminate);
    readFromSock task2(2, mutex, handler, shouldTerminate);
    std::thread th1(&readFromKB::run, &task1);
    std::thread th2(&readFromSock::run, &task2);
    th1.join();
    th2.join();
    delete shouldTerminate;
    return 0;
}