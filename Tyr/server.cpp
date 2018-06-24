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

void Server::update()
{
	while( backlog->getRunning() )
	{
		LogMessage logMessage = {};
		while( backlog->read( messagesRead, &logMessage ) )
		{
			sendMessage( &logMessage );
			messagesRead++;
		}

		Sleep( MESSAGE_DELAY );
	}
}

void Server::setBacklog( Backlog* _backlog )
{
	backlog = _backlog;
}

void Server::sendMessage( LogMessage* message )
{
	//char buffer[MAX_BUF_LEN] = {};
	//int len = message->message.size();
	//if( len < MAX_BUF_LEN )
	//{
	//	memcpy( buffer, message->message.data(), len );
	//	buffer[len] = 0;
	//
	//	send( clientSocket, buffer, len, 0 );
	//}

	send( clientSocket, message->data, message->size, 0 );
}