#include "server.h"

Server::Server()
{
	memset( port, 0, 6 );
}

Server::Server( const char* _port)
{
	strncpy( port, _port, 6 );
	port[5] = 0;
}

bool Server::start()
{
	bool result = false;

	if( port[0] == 0 )
		strncpy( port, DEFAULT_PORT, 6 );

	if( WSAStartup( MAKEWORD( 2, 2 ), &wsadata ) == 0 )
	{
		ZeroMemory( &hints, sizeof(hints) );
		hints.ai_family = AF_INET;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_protocol = IPPROTO_TCP;
		hints.ai_flags = AI_PASSIVE;

		if( getaddrinfo( NULL, port, &hints, &info ) == 0 )
		{
			listenSocket = socket( info->ai_family, info->ai_socktype, info->ai_protocol );
			if( listenSocket != INVALID_SOCKET )
			{
				if( bind( listenSocket, info->ai_addr, (int)info->ai_addrlen ) != SOCKET_ERROR )
				{
					freeaddrinfo( info );

					if( listen( listenSocket, 10 ) != SOCKET_ERROR )
					{
						clientSocket = accept( listenSocket, NULL, NULL );
						if( clientSocket != SOCKET_ERROR )
						{
							closesocket( listenSocket );

							char buf[32] = {};
							int recvbyte = recv( clientSocket, buf, 32, 0 );

							send( clientSocket, buf, recvbyte, 0 );

							shutdown( clientSocket, SD_SEND );

							char message[64] = {};
							_snprintf( message, 64, "Client said: %s", buf );
							MessageBoxA( NULL, message, "Tyr Server", MB_OK ); 
						}
						else
						{
							closesocket( listenSocket );
							WSACleanup();
							MessageBoxA( NULL, "SERVER ERROR 5", "Tyr", MB_OK );
						}
					}
					else
					{
						closesocket( listenSocket );
						WSACleanup();
						MessageBoxA( NULL, "SERVER ERROR 4", "Tyr", MB_OK );
					}
				}
				else
				{
					closesocket( listenSocket );
					freeaddrinfo( info );
					WSACleanup();
					MessageBoxA( NULL, "SERVER ERROR 3", "Tyr", MB_OK );
				}
			}
			else
			{
				freeaddrinfo( info );
				WSACleanup();
				MessageBoxA( NULL, "SERVER ERROR 2", "Tyr", MB_OK );
			}
		}
		else
		{
			WSACleanup();
			MessageBoxA( NULL, "SERVER ERROR 1", "Tyr", MB_OK );
		}
	}
	else
	{
		MessageBoxA( NULL, "SERVER ERROR 0", "Tyr", MB_OK );
	}

	return result;
}

void Server::stop()
{
}