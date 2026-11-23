#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "Constructor called\n";
}

/*BitcoinExchange::BitcoinExchange(int val)
{
	std::cout << "Constructor called\n";
}*/

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	std::cout << "Copy consturctor called\n";
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	std::cout << "Copy assignment operator called\n";
	if(this != &other)
	{
		this->csv = other.csv;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
    std::cout << "Destructor called\n";
}

void	BitcoinExchange::read_csv()
{
	std::fstream file;

	std::string line, val, key;
	std::string kv[2];
	file.open("data.csv", std::ios::in);
	getline(file, line);
	while (getline(file, line))
	{
		std::stringstream s(line);
		getline(s, key, ',');
		getline(s, val, ',');
		csv.insert(std::make_pair(key,val));
	}
}
int	checky(std::string date)
{
		if (date.length() != 4)
			return 0;
		return atoi(date.c_str());
}
int		checkm(std::string date)
{
	int month[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
	for (int i = 0; i < 12; i++)
	{
		if (atoi(date.c_str()) == month[i])
			return (month[i]);
	};
	return(0);
}

bool		checkd(std::string date, int month, int year)
{
	int day[12] = {31,28,31,30,31,30,31,30,31,30,31,30};
	int d = atoi(date.c_str());
	int limit = day[month];
	bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	if (isLeap && month == 1)
		limit = 29;
	if (d > limit || d < 1)
		return false;
	return true;
}
bool	checkdt(std::string input)
{
	std::string date;
	std::stringstream s(input);
	int counter = 0;
	int month = 0;
	int year = 0;
	while(getline(s, date, '-'))
	{
		for (unsigned long i = 0; i < date.size(); i++)
		{
			if(!isdigit(date[i]))
				return (false);
		}
		counter++;
		if (counter == 1)
			if (!(year = checky(date)))
				return false;
		if (counter == 2)
		{
			if (!(month = checkm(date)))
				return false;
		}
		if (counter == 3)
			if (!checkd(date, month - 1, year))
				return false;
	};
	return (true);
}

bool is_valid_number(const std::string& val)
{
    if (val.empty())
	{
        return false;
	}
	size_t start = val.find_first_not_of("\t\r\n ");
	if (start == std::string::npos)
        return false;
	size_t end = val.find_last_not_of(" \t\r\n");
	std::string trim = val.substr(start, end - start + 1);
    size_t i = 0;
    if (trim[0] == '-' ||trim[0] == '+')
        i = 1;

    int dots = 0;
    int digits = 0;
    for (; i < trim.size(); i++)
    {
        if (trim[i] == '.')
        {
            dots++;
            if (dots > 1)
                return false;
        }
        else if (isdigit(static_cast<unsigned char>(trim[i])))
		{
			//std::cout <<"digit_counted" << std::endl;
            digits++;
		}
        else
            return false;
    }
    return digits > 0;
}

void BitcoinExchange::valid_txt(std::string input)
{
	std::fstream file;
	std::map<std::string, std::string> txt;
	std::string line, val, key;
	std::string kv[2];
	file.open(input.c_str(), std::ios::in);
	getline(file, line);
	while (getline(file, line))
	{
		std::stringstream s(line);
		if (!getline(s, key, '|'))
		{
			std::cerr << "bad input => " << line << std::endl;
			continue; 
		}
		if (key.empty())
		{
			std::cerr << "Error: empty date field" << std::endl;
			continue;
		}
			key.erase(key.size() - 1);
		if (key.size() != 10 || key[4] != '-' || key[7] != '-')
		{
			std::cerr << "bad input => " << line << std::endl;
			continue;
		}
		if (!checkdt(key))
		{
			std::cerr << "Error: datetime not only digits" << std::endl;
			continue;
		}
		if (!getline(s, val))
		{
			std::cerr << "no input after delimiter" << std::endl;
			continue;
		}
		else if(!is_valid_number(val))
		{
			std::cerr << "Val: not all digits" << std::endl;
			continue;
		}
		else if (std::atof(val.c_str()) < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		else if (std::atof(val.c_str()) > 1000)
		{
			std::cerr << "Error: number too large" << std::endl;
			continue;
		}
		conv_rate(key, val);
	}
}

void	BitcoinExchange::conv_rate(std::string key, std::string val)
{
	std::map<std::string, std::string>::iterator it;
	it = csv.lower_bound(key);
	if (csv.end() != it && key == it->first)
	{
		float result = std::atof(val.c_str()) * std::atof(it->second.c_str());
		std::cout << key << " =>" << val << " = " << result << std::endl;
		return;
	}
	else
	{
		if (it == csv.begin())
		{
			std::cerr << "Error: no rate available before " << key << std::endl;
			return;
		}
		--it;
	}
		float result = std::atof(val.c_str()) * std::atof(it->second.c_str());
		std::cout << key << " =>" << val << " = " << result << std::endl;
}