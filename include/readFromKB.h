#include <mutex>
#include "../include/connectionHandler.h"


#ifndef CLIENT_READFROMKB_H
#define CLIENT_READFROMKB_H
class readFromKB{
private:
    int id;
    std::mutex &mutex;
    ConnectionHandler &handler;
public:
    readFromKB (int id, std::mutex& mutex, ConnectionHandler& handler);
    std::string getOptNum(std::string line);
    void run();

    short codeToNumber(std::string basicString);
};

#endif //CLIENT_READFROMKB_H
