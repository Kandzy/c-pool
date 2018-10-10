#include "StringConvertor.hpp"

StringConvertor::StringConvertor(void) : _strVal("0")
{
	return ;
}

StringConvertor::StringConvertor(std::string value) : _strVal(value)
{
	return ;
}

StringConvertor::StringConvertor(StringConvertor const &sc)
{
	*this = sc;
	return ;
}

StringConvertor	&StringConvertor::operator=(StringConvertor const &sc)
{
	if(this != &sc)
	{
		this->_strVal = sc._strVal;
	}
	return (*this);
}

void			StringConvertor::setStringValue(std::string value)
{
	this->_strVal = value;
	return;
}

std::string		StringConvertor::getStringValue(void) const
{
	return this->_strVal;
}

StringConvertor::operator char() const
{
	int	result = 0;
	try {
		result = std::stoi(this->_strVal);
	}
	catch (std::exception &ex)
	{
		result = 0;
		throw StringConversionExeption();
	}
	return (static_cast<char>(result));
}

StringConvertor::operator int() const
{
	int	result = 0;
	try {
		result = std::stoi(this->_strVal);
	}
	catch (std::exception &ex)
	{
		throw StringConversionExeption();
	}
	return (result);
}

StringConvertor::operator double() const
{
	double	result = 0.0;
	try {
		result = std::stof(this->_strVal);
	}
	catch (std::exception &ex)
	{
		throw StringConversionExeption();
	}
	return (result);
}

StringConvertor::operator float() const
{
	float	result = 0.0;
	try {
		result = std::stof(this->_strVal);
	}
	catch (std::exception &ex)
	{
		throw StringConversionExeption();
	}
	return (result);
}

StringConvertor::~StringConvertor(void)
{
	return;
}

/*
** STRING CONVERSION EXEPTION
*/

StringConvertor::StringConversionExeption::StringConversionExeption(void)
{
	return;
}

StringConvertor::StringConversionExeption::StringConversionExeption(StringConversionExeption const &sce)
{
	*this = sce;
	return ;
}

StringConvertor::StringConversionExeption &StringConvertor::StringConversionExeption::operator=(StringConversionExeption const &sce)
{
	(void)sce;
	return (*this);
}

const char*	StringConvertor::StringConversionExeption::what() const throw()
{
	return ("impossible");
}

StringConvertor::StringConversionExeption::~StringConversionExeption(void) throw()
{
	return ;
}