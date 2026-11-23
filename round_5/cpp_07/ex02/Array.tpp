#include "Array.hpp"

template <typename T>
Array<T>::Array() : num(0), Ar(new T[0])
{

}

template <typename T>
Array<T>::Array(int n) : num(n), Ar(new T[n]())
{

}
template <typename T>
Array<T>::Array(const Array<T>& other) : num(other.num), Ar(new T[other.num])
{
	this->num = other.num;
	this->Ar = new T[other.num];
	try
	{
		for (int i = 0; i < other.num; i++)
    		this->Ar[i] = other.Ar[i];
	}
	catch(...)
	{
		delete[] this->Ar;
		throw;
	}

}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>&other)
{
    if (this != &other)
    {
		T* NewAr = new T[other.size()];
		try
		{
			for (int i = 0; i < other.size(); i++)
				NewAr[i] = other.Ar[i];
		}
		catch (...)
		{
			delete[] NewAr;
			throw;
		}
		delete[] this->Ar;
		this->Ar = NewAr;
		this->num = other.num;	
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](int idx)
{
	if(idx < 0 || idx >= size())
		throw Array<T>::OutofBoundsException();
	return (Ar[idx]);
}

template <typename T>
const T& Array<T>::operator[](int idx) const
{
	if(idx < 0 || idx >= size())
		throw Array<T>::OutofBoundsException();
	return (Ar[idx]);
}


template <typename T>
Array<T>::~Array()
{
	delete[] Ar;
}
template <typename T>
int	Array<T>::size() const
{
	return (num);
}

template <typename T>
const char* Array<T>::OutofBoundsException::what() const throw()
{
	return ("Index out of bounds\n");
}