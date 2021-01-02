
#include "../include/readFromKB.h"
#include <mutex>
#include <iostream>

readFromKB::readFromKB(int id, std::mutex &mutex, ConnectionHandler &handler): id(id), mutex(mutex), handler(handler)  {

}

void readFromKB::run() {

        const short bufsize = 1024;
        char buf[bufsize];
        short spaceLoc = 0;
        while (buf[spaceLoc] != ' ')
            spaceLoc++;
        std::cin.getline(buf, bufsize);
        std::string optCode(buf, spaceLoc);
        handler.sendLine(optCode, buf);



        //handler.sendLine(line); //fix encoding

}

short readFromKB::codeToNumber(std::string basicString) {
    return 0;
}


