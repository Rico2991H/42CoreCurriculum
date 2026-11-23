#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
class span
{
	public:
		span();
		span(unsigned int N);
		span(const span& other);
		span& operator=(const span& other);
		~span();
		void	addNumber(int N);
		template <typename InputIterator>
		void	addMNumbers(InputIterator begin, InputIterator end)
		{
			for(; begin != end; begin++)
				addNumber(*begin);
		}
		int		shortestSpan();
		int		longestSpan();
		class VFullException : public std::exception
		{
			public:
				const char* what() const throw();
		};

	private:
		std::vector<int> V;
		unsigned int S;

};

#endif
