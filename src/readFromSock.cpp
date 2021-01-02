
#include "../include/readFromSock.h"
#include <mutex>

readFromSock::readFromSock(int id, std::mutex &mutex, ConnectionHandler &handler, bool* shouldTerminate): id(id), mutex(mutex), handler(handler), shouldTerminate(shouldTerminate){

}
void readFromSock::run() {

}
