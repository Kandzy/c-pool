#include "Logger.hpp"

int main()
{
	Logger logger("Log");
	logger.log("console", "new log to this insert");
	logger.log("Console", "one more log");
	logger.log("file", "this is file log");
	logger.log("File", "this is big file log");
	return (0);
}