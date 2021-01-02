
#include "../include/readFromSock.h"
#include <mutex>
using namespace std;


readFromSock::readFromSock(int id, std::mutex &mutex, ConnectionHandler &handler, bool* shouldTerminate): id(id), mutex(mutex), handler(handler), shouldTerminate(shouldTerminate){

}
void readFromSock::run() {
    while (!shouldTerminate) {
        char answer[4];
        handler.getBytes(answer, 4);
        if (answer[1] == 3) {
            string output = "ERROR ";
            if (answer[2] != 0) output = output + answer[2] + output[3];
            else output = output + answer[2];
            cout << output << std::endl;
        }
        else {
            cout << "ACK " << answer[2] << answer[3] << std::endl;
            //print additional
            string optional;
            handler.getLine(optional);
            if (optional != "")
                cout << optional << std::endl;
            if (answer[2] == '4')
                *shouldTerminate = true;
        }
    }
}
