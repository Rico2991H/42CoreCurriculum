#include "Serializer.hpp"

#include <iostream>
#include <string>


Serializer::Serializer()
{
	std::cout << "Constructor called\n";
}

Serializer::Serializer(const Serializer& other)
{
	std::cout << "Copy constructor called\n";
	(void)other;
}

Serializer& Serializer::operator=(const Serializer& other)
{
	std::cout << "Copy assignment operator called\n";
	if(this != &other)
	{	
	}
	return (*this);
}

Serializer::~Serializer()
{
    std::cout << "Destructor called\n";
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t ptr)
{
	return (reinterpret_cast<Data*>(ptr));
}