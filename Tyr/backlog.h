#pragma once

#include <Windows.h>
#include <vector>
#include <string>

#define LOG_MESSAGE_MAX_LEN 128
struct LogMessage
{
	union
	{
		char data[LOG_MESSAGE_MAX_LEN+1];
		struct
		{
			char size;
			char message[LOG_MESSAGE_MAX_LEN];
		};
	};
};

#define DEFAULT_LOG_PATH "./scripts/tmp/log.txt"
class Backlog
{
public:
	Backlog();
	~Backlog();

	void log( const char* message );
	void log( const std::string& message );

	bool read( unsigned long count, LogMessage* out );

	void setRunning( bool running );
	bool getRunning() const;

private:
	HANDLE mutex;
	std::vector<LogMessage> messages;
	bool running;
	FILE* logHandle;
};