#pragma once

#include <WinSock2.h>
#include <ws2tcpip.h>
#include <cstdio>
#include "backlog.h"

#define DEFAULT_PORT "15015"
#define MAX_BUF_LEN 512
#define MESSAGE_DELAY 1000 //ms

class Server
{
public:
	Server();
	Server( const char* port );

	bool start();
	void stop();
	void update();

	void setBacklog( Backlog* backlog );

private:
	void sendMessage( LogMessage* message );

	char port[6];
	WSADATA wsadata;
	SOCKET listenSocket;
	SOCKET clientSocket;
	struct addrinfo hints;
	struct addrinfo* info;
	Backlog* backlog;
	unsigned long messagesRead;
};