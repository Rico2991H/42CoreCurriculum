#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <exception>


template<typename T>
class Array
{
	private:
		int num;
		T* Ar;
	public:
		Array();
		Array(int n);
		Array(const Array<T>& other);
		Array<T>& operator=(const Array<T>&other);
		T& operator[](int idx);
		const T& operator[](int idx) const;
		~Array();
		int		size() const;
		class OutofBoundsException : public std::exception
		{
			public:
				const char* what() const throw();
		};
	
};

#include "Array.tpp"

#endif