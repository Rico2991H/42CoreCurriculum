#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP


#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <map>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		//BitcoinExchange(int val);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
		void	read_csv();
		void	valid_txt(std::string input);
		void	conv_rate(std::string key, std::string val);
	private:
		std::map<std::string, std::string> csv;
};

#endif
