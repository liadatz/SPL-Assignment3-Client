
#include "../include/readFromSock.h"
#include <mutex>

readFromSock::readFromSock(int id, std::mutex &mutex, ConnectionHandler &handler): id(id), mutex(mutex), handler(handler){

}
void readFromSock::run() {

}
