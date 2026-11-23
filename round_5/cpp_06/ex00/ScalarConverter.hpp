#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cmath>

class ScalarConverter
{
	public:
		static void	convert(std::string str);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();
};

bool	checkChar(std::string str);
bool	checkInt(std::string str);
bool	checkFloat(std::string str);
bool	checkDouble(std::string str);
void	convChar(std::string str);
void	convInt(std::string str);
void	convFloat(std::string str);
void	convDouble(std::string str);
bool	checkSpecial(std::string str);

#endif
