#include "span.hpp"

int main()
{
	span x = span(3);
	span y = span(100002);
	try
	{

		std::vector<int> v2;
		for (int i = 0; i < 100001; i++)
			v2.push_back(i);
		x.addNumber(1);
		x.addNumber(10);
		x.addNumber(5);
		y.addMNumbers(v2.begin(), v2.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << x.longestSpan() << std::endl;
		std::cout << x.shortestSpan() << std::endl;
		std::cout << y.longestSpan() << std::endl;
		std::cout << y.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}