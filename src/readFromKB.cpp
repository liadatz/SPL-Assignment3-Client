
#include "../include/readFromKB.h"
#include <mutex>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "boost/lexical_cast.hpp"

using namespace std;


readFromKB::readFromKB(int id, std::mutex &mutex, ConnectionHandler &handler, bool* shouldTerminate): id(id), mutex(mutex), handler(handler), shouldTerminate(shouldTerminate)  {}

void readFromKB::run() {
    while (!shouldTerminate) {
        const short bufsize = 1024;
        char buf[bufsize];
        cin.getline(buf, bufsize);
        string line(buf);
        vector<string> message;
        boost::split(message, line, boost::is_any_of(" "));
        char opCode[2];
        char courseNum[2];

        if (message[0] == "ADMINREG") {
            shortToBytes(1, opCode);
            handler.sendBytes(opCode, 2);
            handler.sendLine(message[1]);
            handler.sendLine(message[2]);
        }
        else if (message[0] == "STUDENTREG") {
            shortToBytes(2, opCode);
            handler.sendBytes(opCode, 2);
            handler.sendLine(message[1]);
            handler.sendLine(message[2]);
        }
        else if (message[0] == "LOGIN") {
            shortToBytes(3, opCode);
            handler.sendBytes(opCode, 2);
            handler.sendLine(message[1]);
            handler.sendLine(message[2]);
        }
        else if (message[0] == "LOGOUT") {
            shortToBytes(4, opCode);
            handler.sendBytes(opCode, 2);
        }
        else if (message[0] == "COURSEREG") {
            shortToBytes(5, opCode);
            handler.sendBytes(opCode, 2);
            short courseNumber = boost::lexical_cast<short>(message[1]);
            shortToBytes(courseNumber, courseNum);
            handler.sendBytes(courseNum, 2);
        }
        else if (message[0] == "KDAMCHECK") {
            shortToBytes(6, opCode);
            handler.sendBytes(opCode, 2);
            short courseNumber = boost::lexical_cast<short>(message[1]);
            shortToBytes(courseNumber, courseNum);
            handler.sendBytes(courseNum, 2);
        }
        else if (message[0] == "COURSESTAT") {
            shortToBytes(7, opCode);
            handler.sendBytes(opCode, 2);
            short courseNumber = boost::lexical_cast<short>(message[1]);
            shortToBytes(courseNumber, courseNum);
            handler.sendBytes(courseNum, 2);
        }
        else if (message[0] == "STUDENTSTAT") {
            shortToBytes(8, opCode);
            handler.sendBytes(opCode, 2);
            handler.sendLine(message[1]);
        }
        else if (message[0] == "ISREGISTERED") {
            shortToBytes(9, opCode);
            handler.sendBytes(opCode, 2);
            short courseNumber = boost::lexical_cast<short>(message[1]);
            shortToBytes(courseNumber, courseNum);
            handler.sendBytes(courseNum, 2);
        }
        else if (message[0] == "UNREGISTER") {
            shortToBytes(10, opCode);
            handler.sendBytes(opCode, 2);
            short courseNumber = boost::lexical_cast<short>(message[1]);
            shortToBytes(courseNumber, courseNum);
            handler.sendBytes(courseNum, 2);
        }
        else if (message[0] == "MYCOURSES") {
            shortToBytes(11, opCode);
            handler.sendBytes(opCode, 2);
        }
        else cout << "Illegal command!"; // delete
    }
}

void readFromKB::shortToBytes(short num, char* bytesArr) {
    bytesArr[0] = ((num >> 8) & 0xFF);
    bytesArr[1] = (num & 0xFF);
}


