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
    void run();
};

#endif //CLIENT_READFROMKB_H
