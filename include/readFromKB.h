#include <mutex>
#include "../include/connectionHandler.h"


#ifndef CLIENT_READFROMKB_H
#define CLIENT_READFROMKB_H
class readFromKB{
private:
    int id;
    std::mutex &mutex;
    ConnectionHandler &handler;
    bool* shouldTerminate;
public:
    readFromKB (int id, std::mutex& mutex, ConnectionHandler& handler, bool* shouldTerminate);
    std::string getOptNum(std::string line);
    void run();

    short codeToNumber(std::string basicString);

    void shortToBytes(short num, char *bytesArr);
};

#endif //CLIENT_READFROMKB_H
