#include "RPN.hpp"

template<typename T, class Container>
RPN<T, Container>::RPN()
{
	std::cout << "Constructor called\n";
}

template<typename T, class Container>
RPN<T, Container>::RPN(const RPN& other) : std::stack<T, Container>(other)
{
	std::cout << "Copy constructor called\n";
	//*this = other;
}

template<typename T, class Container>
RPN<T, Container>& RPN<T, Container>::operator=(const RPN& other)
{
	std::cout << "Copy assignment operator called\n";
	if(this != &other)
	{
		std::stack<T, Container>::operator=(other);
	}
	return (*this);
}

template<typename T, class Container>
RPN<T, Container>::~RPN()
{
    std::cout << "Destructor called\n";
}

template<typename T, class Container>
bool	RPN<T, Container>::calculate(char op)
{
	int			result, temp;
	std::stringstream n;
	if (this->size() < 2)
	{
		std::cerr << "Error: Needs two terms in container." << std::endl;
		return false;
	}
	temp = atoi(this->top().c_str());
	this->pop();
	result = atoi(this->top().c_str());
	this->pop();
	switch(op)
	{
		case '-':
			result -= temp;
			break;
		case '+':
			result += temp;
			break;
		case '*':
			result *= temp;
			break;
		case '/':
			if (temp == 0)
			{
				std::cerr << "Division by zero error" << std::endl;
				return false;
			}
			result /= temp;
			break;
	}
	n << result;
	this->push(n.str());
	return true;
}

template<typename T, class Container>
void	RPN<T, Container>::split_input(std::string input)
{
	std::stringstream s(input);
	std::string line;
	while(getline(s, line, ' '))
	{
		if(line.size() == 2 && line[0] == '-' && isdigit(line[1]))
		{
			this->push(line);
		}
		else if(line.size() == 1 && isdigit(line[0]))
		{
			this->push(line);
		}
		else if(line == "+" || line == "*" || line == "-" || line == "/")
		{
			if(!this->calculate(line[0]))
				return;
		}
		else
		{
			std::cerr << "Error" << std::endl;
			return;
		}
	}
	if (this->size() == 1)
		std::cout << this->top() << std::endl;
	else
		std::cerr << "Error: leftover terms in container" << std::endl;
}
