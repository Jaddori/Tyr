#pragma once

#include <WinSock2.h>
#include <ws2tcpip.h>
#include <cstdio>

#define DEFAULT_PORT "15015"

class Server
{
public:
	Server();
	Server( const char* port );

	bool start();
	void stop();

private:
	char port[6];
	WSADATA wsadata;
	SOCKET listenSocket;
	SOCKET clientSocket;
	struct addrinfo hints;
	struct addrinfo* info;
};