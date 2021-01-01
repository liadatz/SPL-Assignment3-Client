
#include "../include/readFromKB.h"
#include <mutex>
#include <iostream>

readFromKB::readFromKB(int id, std::mutex &mutex, ConnectionHandler &handler): id(id), mutex(mutex), handler(handler)  {

}

void readFromKB::run() {
    while (1) {
        const short bufsize = 1024;
        char buf[bufsize];
        std::cin.getline(buf, bufsize);
        std::string line(buf);
        handler.sendLine(line); //fix encoding
    }
}


