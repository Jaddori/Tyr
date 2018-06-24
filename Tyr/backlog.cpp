#include "backlog.h"

Backlog::Backlog()
	: running( true )
{
	mutex = CreateMutex( NULL, FALSE, NULL );
	logHandle = fopen( DEFAULT_LOG_PATH, "w" );
}

Backlog::~Backlog()
{
	if( logHandle )
		fclose( logHandle );
}

void Backlog::log( const char* message )
{
	WaitForSingleObject( mutex, INFINITE );

	LogMessage logMessage = {};
	int len = strlen( message );
	if( len < LOG_MESSAGE_MAX_LEN )
	{
		strcpy( logMessage.message, message );
		logMessage.size = len + 1;

		messages.push_back( logMessage );

		fprintf( logHandle, "%s\n", message );
		fflush( logHandle );
	}

	ReleaseMutex( mutex );
}

bool Backlog::read( unsigned long count, LogMessage* out )
{
	bool result = false;

	WaitForSingleObject( mutex, INFINITE );

	if( messages.size() > count )
	{
		*out = messages[count];
		result = true;
	}

	ReleaseMutex( mutex );

	return result;
}

void Backlog::setRunning( bool _running )
{
	running = _running;
}

bool Backlog::getRunning() const
{
	return running;
}