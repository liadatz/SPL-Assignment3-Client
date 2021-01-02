CFLAGS:=-c -Wall -Weffc++ -g -std=c++11 -Iinclude
LDFLAGS:=-lboost_system -pthread

all: BGRSclient
    @echo 'Building target: Client'
    @echo 'Invoking: C++ Linker'
	g++ -o bin/BGRSclient bin/BGRSClient.o bin/connectionHandler.o bin/readFromKB.o bin/readFromSock.o $(LDFLAGS)
    @echo 'Finished building target: Client'
    @echo ' '

bin/BGRSClient.o: src/BGRSClient.cpp
	g++ $(CFLAGS) -o bin/BGRSClient.o src/BGRSClient.cpp

bin/connectionHandler.o: src/connectionHandler.cpp
	g++ $(CFLAGS) -o bin/connectionHandler.o src/connectionHandler.cpp

bin/readFromKB.o: src/readFromKB.cpp
	g++ $(CFLAGS) -o bin/readFromKB.o src/readFromKB.cpp

bin/readFromSock.o: src/readFromSock.cpp
	g++ $(CFLAGS) -o bin/readFromSock.o src/readFromSock.cpp

.PHONY: clean
clean:
    rm -f bin/*