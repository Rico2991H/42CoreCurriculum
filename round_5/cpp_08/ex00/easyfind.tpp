#include "easyfind.hpp"

template <typename T>
typename T::iterator	easyfind(T& ar, int x)
{

	typename T::iterator it = std::find(ar.begin(), ar.end(), x);
	if (it == ar.end())
        throw NothingFoundException();
	return (it);
} 
const char* NothingFoundException::what() const throw()
{
	return ("Value not found\n");
}