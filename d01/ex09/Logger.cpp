#include "Logger.hpp"

Logger::Logger(std::string name) : filename(name){}

void Logger::logToConsole(std::string const &logMsg)
{
	std::cout << logMsg << std::endl;
}

void Logger::logToFile(std::string const &logMsg)
{
	std::string logFile = this->filename;
	std::ofstream file;

	file.open(logFile, std::ofstream::out | std::ofstream::app);	
	file << logMsg << std::endl;
	file.close();
	return ;
}

void Logger::log(std::string const &dest, std::string const &message)
{
	std::string logs = this->makeLogEntry(message);
	void (Logger::*pfunc[])(std::string const &) = {&Logger::logToConsole, &Logger::logToFile};
	std::string commands_dest[] ={"console", "file", "Console", "File"};

	for (int i = 0; i < 4; i++)
	{
		if (commands_dest[i] == dest)
		{
			(this->*pfunc[i % 2])(logs);
		}
	}
}

std::string Logger::makeLogEntry(std::string logMsg)
{
	std::string lol= "gdfg";
	time_t now = time(0);
	tm* localtm = localtime(&now);
	std::string data = asctime(localtm);
	logMsg = "*\nTime: " + data + "Log: " + logMsg + "\n*";
	return logMsg;
}