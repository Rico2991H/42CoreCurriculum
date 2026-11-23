#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <deque>
#include <sstream>
#include <cstdlib>

template<typename T, class Container = std::deque<T> >
class RPN : public std::stack<T, Container>
{
	public:
		typedef typename Container::iterator iterator;
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();
		void	split_input(std::string input);
		bool	calculate(char op);

	protected:


	private:

};

#include "RPN.tpp"

#endif
