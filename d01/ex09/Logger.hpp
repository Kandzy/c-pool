#ifndef LOGGER_HPP
# define LOGGER_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>

class	Logger 
{
	public:
						Logger(std::string name);
		void			log(std::string const &dest, std::string const &message);
	private:
		std::string		filename;
		void			logToConsole(std::string const &logMsg);
		void			logToFile(std::string const &logMsg);
		std::string		makeLogEntry(std::string logMsg);
}; 

#endif