#include "conversion.hpp"

void checkForm(std::string &str)
{
	bool check_f = false;
	size_t i = 0;

	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (i && str[i] == '.' && str[i - 1] != '+' && str[i - 1] != '-')
	{
		check_f = true;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (check_f && str[i] == 'f')
		i++;
	if (i != str.length())
		throw (ImpossibleConversionException());
}

void printChar(std::string &str)
{
	int c;
	std::stringstream stream(str);

	try
	{
		std::cout << "Char: ";
		checkForm(str);
		stream >> c;
		if (c < 0 || c > 127)
			throw (ImpossibleConversionException());
		else if (c < 32 || c == 127)
			throw (NonDisplayableCharacterExcpetion());
		std::cout << static_cast<char>(c) << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void printInt(std::string &str)
{
	long long int nb;
	std::stringstream stream(str);

	try
	{
		std::cout << "Int: ";
		checkForm(str);
		stream >> nb;
		if (stream.str().length() > 10 || nb < std::numeric_limits<int>::min() || nb > std::numeric_limits<int>::max())
			throw (ImpossibleConversionException());
		std::cout << static_cast<int>(nb) << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void printFloat(std::string &str)
{
	int intpart;
	float decpart;
	double nb;
	std::stringstream stream(str);

	try
	{
		std::cout << "Float: ";
		if (str == "-inff" || str == "+inff" || str == "inff"
			|| str == "nanf" || str == "-inf" || str == "+inf"
			|| str == "inf" || str == "nan")
		{
			if (str.find('+') != std::string::npos)
				str.erase(str.find('+'), 1);
			std::cout << str;
			if (str == "-inf" || str == "+inf" || str == "nan")
				std::cout << "f";
			std::cout << std::endl;
			return ;
		}
		checkForm(str);
		stream >> nb;
		if (nb > std::numeric_limits<float>::max() || nb < std::numeric_limits<float>::min())
			throw (ImpossibleConversionException());
		intpart = static_cast<int>(nb);
		decpart = static_cast<float>(nb - intpart);
		if (!decpart)
			std::cout << static_cast<float>(nb) << ".0f" << std::endl;
		else
			std::cout << std::setprecision(8) << static_cast<float>(nb) << "f" << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void printDouble(std::string &str)
{
	int intpart;
	double decpart;
	double nb;
	std::stringstream stream(str);

	try
	{
		std::cout << "Double: ";
		if (str == "-inff" || str == "+inff" || str == "inff"
			|| str == "nanf" || str == "-inf" || str == "+inf"
			|| str == "inf" || str == "nan")
		{
			if (str == "-inff" || str == "+inff"
				|| str == "nanf")
				str.erase(str.size() - 1);
			if (str.find('+') != std::string::npos)
				str.erase(str.find('+'), 1);
			std::cout << str << std::endl;
			return ;
		}
		checkForm(str);
		stream >> nb;
		intpart = static_cast<int>(nb);
		decpart = static_cast<double>(nb - intpart);
		if (!decpart)
			std::cout << static_cast<double>(nb) << ".0" << std::endl;
		else
			std::cout << std::setprecision(8) << static_cast<double>(nb) << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
}