#pragma once
#include <limits>
#include <sstream>
#include <iostream>
#include <stdexcept>

class ImpossibleConversionException: public std::exception
{
	public:
		virtual const char *what(void) const throw()
		{
			return ("impossible.");
		}
};

class NonDisplayableCharacterExcpetion: public std::exception
{
	public:
		virtual const char *what(void) const throw()
		{
			return ("Non displayable.");
		}
};

void printInt(std::string &str);
void checkForm(std::string &str);
void printChar(std::string &str);
void printFloat(std::string &str);
void printDouble(std::string &str);
