#include <mutex>
#include "connectionHandler.h"

#ifndef CLIENT_READFROMSOCK_H
#define CLIENT_READFROMSOCK_H


class readFromSock{
private:
    int id;
    std::mutex &mutex;
    ConnectionHandler &handler;
public:
    readFromSock (int id, std::mutex& mutex, ConnectionHandler &handler);
    void run();
};

#endif //CLIENT_READFROMSOCK_H
