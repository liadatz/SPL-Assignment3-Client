#include <mutex>

#ifndef CLIENT_READFROMSOCK_H
#define CLIENT_READFROMSOCK_H


class readFromSock{
private:
    int _id;
    std::mutex & _mutex;
public:
    readFromSock (int id, std::mutex& mutex);
    void run();
};

#endif //CLIENT_READFROMSOCK_H
