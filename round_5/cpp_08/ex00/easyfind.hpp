#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <exception>

class NothingFoundException : public std::exception
{
	public:
		const char* what() const throw();
};

template <typename T>
typename T::iterator	easyfind(T& ar, int x);


#include "easyfind.tpp"

#endif