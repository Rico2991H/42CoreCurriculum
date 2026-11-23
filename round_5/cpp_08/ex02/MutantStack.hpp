#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <string>
#include <iostream>
#include <stack>
#include <deque>
#include <vector>

template <typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
	MutantStack() {}
	MutantStack(const MutantStack& other) : std::stack<T, Container>(other) {}
	MutantStack &operator=(const MutantStack& other)
	{
		if (this != &other)
		{
			std::stack<T, Container>::operator=(other);
		}
		return (*this);
	}
	~MutantStack(){}
	typedef typename std::stack<T, Container>::container_type::iterator iterator;
	iterator begin() { return (this->c.begin()); }
	iterator end() {return (this->c.end());}

	private:

};
#endif