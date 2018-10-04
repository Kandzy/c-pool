#include "Sed.class.hpp"

Sed::Sed(std::string filename, std::string toFind, std::string toReplace)
{
	this->fileOpen.open(filename, std::ifstream::in);
	this->toFind = toFind;
	this->toReplace = toReplace;
	this->inputFile = filename + ".replace";
	this->text = "";
	if (this->fileOpen.is_open())
	{
		return ;
	}
	else
	{
		std::cout << "Error : Cant find this file. Please check you input and try again try again." << std::endl;
		return;
	}
}

void Sed::stringReplace()
{
	std::string		line = "";
	if (this->fileOpen.is_open())
	{
		this->inFl.open (this->inputFile, std::ofstream::out);
		if (this->inFl.fail())
		{
			std::cout << "Error : Cant create file!" << std::endl;
			return ;
		}
		bool firstLine = true;
		while (getline(this->fileOpen, line))
		{
			if (!firstLine)
				this->text = this->text + '\n';
			this->text += line;
			firstLine = false;
		}
		bool repl = true;
		int	pos = 0;
		do
		{
			std::string::size_type  index = this->text.find(this->toFind, pos);
			if (index != std::string::npos){
				this->text.replace(index, this->toFind.length(), this->toReplace);
				pos = index + this->toReplace.length();
			}
			else 
			{
				repl = false;
			}
		} while (repl);
		this->inFl << this->text << std::endl;
	}
	else
	{
		std::cout << "Error : Cant find this file. Please check you input and try again try again." << std::endl;
		return;
	}
}

Sed::~Sed()
{
	this->fileOpen.close();
	this->inFl.close();
}