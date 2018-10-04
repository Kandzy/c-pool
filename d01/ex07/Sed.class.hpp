#ifndef SED_CLASS_HPP
#define SED_CLASS_HPP

#include <iostream>
#include <fstream>
#include <string>

class Sed{
	public:
		Sed(std::string filename, std::string toFind, std::string toReplace);
		~Sed();
		void stringReplace();
	private:
		std::ifstream fileOpen;
		std::ofstream inFl;
		std::string	inputFile;
		std::string text;
		std::string toFind;
		std::string toReplace;
};

#endif