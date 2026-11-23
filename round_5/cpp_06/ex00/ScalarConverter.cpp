#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "Constructor called\n";
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	std::cout << "Copy constructor called\n";
	*this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	std::cout << "Copy assignment operator called\n";
	if(this != &other)
	{

		return(*this);
	}
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "Destructor called\n";
}
void	ScalarConverter::convert(std::string str)
{
	if (!checkSpecial(str))
	{
		if (checkChar(str))
			convChar(str);
		else if (checkInt(str))
			convInt(str);
		else if (checkFloat(str))
			convFloat(str);
		else if (checkDouble(str))
			convDouble(str);
		else
			std::cout << "input does not match any type \n";
	}
}