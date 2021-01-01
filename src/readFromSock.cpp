
#include "../include/readFromSock.h"
#include <mutex>

readFromSock::readFromSock(int id, std::mutex &mutex): _id(id), _mutex(mutex) {

}
void readFromSock::run() {

}
