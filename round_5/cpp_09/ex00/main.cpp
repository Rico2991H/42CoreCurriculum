#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		BitcoinExchange btc;
		btc.read_csv();
		btc.valid_txt(argv[1]);
	}
	else
		std:: cout << "program takes exactly 1 argument" << std::endl;
}
