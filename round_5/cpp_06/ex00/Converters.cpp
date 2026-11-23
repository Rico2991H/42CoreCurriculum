
#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <cerrno>


bool	checkChar(std::string str)
{
	if (str.length() == 1 && !isdigit(str[0]))
		return (true);
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'' && !isdigit(str[1]))
		return (true);
	return (false);
}

bool	checkInt(std::string str)
{
	if (str.empty())
		return (false);
	char *end = NULL;
	long l = strtol(str.c_str(), &end, 10);
	if (*end != '\0' )
		return (false);
	if (l > std::numeric_limits<int>::max() || l < std::numeric_limits<int>::min())
		return (false);
	return (true);
}
bool	checkFloat(std::string str)
{
	if (str.empty())
		return (false);
	errno = 0;
	char *end = NULL;
	double d = strtod(str.c_str(), &end);
	if ((str[0] != '-' && str[0] != '+' && str[0] != '.' && !isdigit(str[0])))
		return (false);
	if (errno == ERANGE)
		return (false);
	if (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max())
		return (false);
	if (!(*end == 'f' && *(end + 1) == '\0'))
		return (false);
	return (true);
}

bool	checkDouble(std::string str)
{
	if (str.empty())
		return (false);
	errno = 0;
	int i = 0;
	int dots = 0;
	char *end = NULL;
	while (str[i])
	{
		if (str[i] == '.')
			dots++;
		i++;
	}
	strtod(str.c_str(), &end);
	if (dots != 1)
		return (false);
	if (errno == ERANGE)
		return (false);
	if (*end != '\0')
		return (false);
	return (true);
}

bool	checkSpecial(std::string str)
{
	if (str == "nanf" || str == "nan")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << "nanf" << std::endl;
		std::cout << "double: " << "nan" << std::endl;			
		return (true);	
	}
	else if (str == "-inff" || str == "-inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << "-inff" << std::endl;
		std::cout << "double: " << "-inf" << std::endl;
		return (true);
	}
	else if (str == "inff" || str == "inf" || str == "+inff" || str == "+inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << "inff" << std::endl;
		std::cout << "double: " << "inf" << std::endl;
		return (true);
	}
	return (false);
}

void	convChar(std::string str)
{
	char c = 0;
	if (str.length() == 1)
	{
		c = str[0];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;	
	}
	else
	{
		c = str[1];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;	
	}
}

void	convInt(std::string str)
{
	int i = atoi(str.c_str());
	if(i > 32 && i < 127)
		std::cout << "char: " << static_cast<char>(i) << std::endl;
	else
		std::cout << "char: non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void	convFloat(std::string str)
{
	char *end = NULL;
	float f = strtof(str.c_str(), &end);
	if(f > 32 && f < 127)
		std::cout << "char: " << static_cast<char>(f) << std::endl;
	else
		std::cout << "char: non displayable" << std::endl;
	if(f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	if (f == std::floor(f))	
		std::cout << "float: " << f << ".0f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
	if (f == std::floor(f))
    	std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
	else
   		std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void	convDouble(std::string str)
{
	char *end = NULL;
	double d = strtod(str.c_str(), &end);
	if(d > 32 && d < 127)
		std::cout << "char: " << static_cast<char>(d) << std::endl;
	else
		std::cout << "char: non displayable" << std::endl;
	if(d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	if(d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max())
		std::cout << "float: " << static_cast<float>(d) << std::endl;
	else
	{
		if (d == std::floor(d))
			std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
		else 
			std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	}
	if (d == std::floor(d))
    	std::cout << "double: " << d << ".0" << std::endl;
	else
    	std::cout << "double: " << d << std::endl;
}