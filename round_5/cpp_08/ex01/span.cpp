#include "span.hpp"

// constructors

span::span() : V(0) , S(0)
{

	std::cout << "Def Constructor called\n";
}

span::span(unsigned int N) : S(N)
{
	V.reserve(N);
	std::cout << "Constructor called\n";
}

span::span(const span& other)
{
	std::cout << "Copy constructor called\n";
	*this = other;
}

span& span::operator=(const span& other)
{
	std::cout << "Copy assignment operator called\n";
	if(this != &other)
	{
		this->V = other.V;
		this->S = other.S;
	}
	return (*this);
}

span::~span()
{
    std::cout << "Destructor called\n";
}

// member functions

const char* span::VFullException::what() const throw()
{
	return ("Vector is full\n");
}

void	span::addNumber(int Num)
{
	if (V.size() < this->S)
		V.push_back(Num);
	else
		throw VFullException();
}

int		span::shortestSpan()
{
	if(V.size() < 2)
		throw std::out_of_range("too little values in vector");
	std::vector<int> sorted(V);
	std::sort(sorted.begin(), sorted.end());
	int minDiff = sorted[1] - sorted[0];
	for (size_t i = 2; i < sorted.size(); i++)
	{
		int diff = sorted[i] - sorted[i - 1];
		if (diff < minDiff)
			minDiff = diff;
	}
	return (minDiff);
}
int		span::longestSpan()
{
	if (V.size() < 2)
	{
		throw std::out_of_range("too little values in vector");
	}
	std::vector<int> sorted(V);
	std::sort(sorted.begin(), sorted.end());
	return (sorted.back() - sorted.front());
}