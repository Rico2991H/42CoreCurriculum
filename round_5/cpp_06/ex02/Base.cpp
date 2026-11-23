#include "Base.hpp"
#include <string>
#include <iostream>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
    std::cout << "Destructor called\n";
}

Base*	generate(void)
{
	time_t t;
	time(&t);
	struct tm dt = *localtime(&t);
	int sec = dt.tm_sec;
	if (sec % 3 == 1)
		return(new A());
	else if (sec % 3 == 2)
		return(new B());
	else
		return(new C());
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "This is A*" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "This is B*" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "This is C*" << std::endl;
	else
		std::cout << "No type found " << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A& aRef = dynamic_cast<A&>(p);
		(void)aRef;
		std::cout << "This is A" << std::endl;
	}
	catch (std::exception&)
	{
		try
		{
			B& bRef = dynamic_cast<B&>(p);
			(void)bRef;
			std::cout << "This is B" << std::endl;
		}
		catch (std::exception&)
		{
			try
			{
				C& cRef = dynamic_cast<C&>(p);
				(void)cRef;
				std::cout << "This is C" << std::endl;
			}
			catch (std::exception&)
			{
				std::cout << "No type found" << std::endl;
			}
		}
	}
}

