
#include "../include/readFromKB.h"
#include <mutex>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "boost/lexical_cast.hpp"

using namespace std;


readFromKB::readFromKB(int id, std::mutex &mutex, ConnectionHandler &handler, bool* shouldTerminate): id(id), mutex(mutex), handler(handler), shouldTerminate(shouldTerminate)  {

}

void readFromKB::run() {

        const short bufsize = 1024;
        char buf[bufsize];
//        short spaceLoc = 0;
//        while (buf[spaceLoc] != ' ')
//            spaceLoc++;
        cin.getline(buf, bufsize);
        string line(buf);
        vector <string> message;
        boost::split(message, line, boost::is_any_of(" "));
        char opCode[2];

        if (message[0] == "ADMINREG") {
            shortToBytes(1, opCode);
            handler.sendBytes(opCode, 2);
            handler.sendLine(message[1]);
            handler.sendLine(message[2]);
        }


//        std::string optCode(buf, spaceLoc);
//        handler.sendLine(optCode, buf);



        //handler.sendLine(line); //fix encoding

}

short readFromKB::codeToNumber(std::string basicString) {
    return 0;
}

void readFromKB::shortToBytes(short num, char* bytesArr) {
    bytesArr[0] = ((num >> 8) & 0xFF);
    bytesArr[1] = (num & 0xFF);
}


