#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	std::cout << "Constructor called\n";
}

Intern::Intern(const Intern& other)
{
	std::cout << "Copy consturctor called\n";
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	std::cout << "Copy assignment operator called\n";
	if(this != &other)
	{
		return (*this);
	}
	return (*this);
}

Intern::~Intern()
{
    std::cout << "Destructor called\n";
}

AForm* Intern::makeForm(std::string n, std::string t)
{
	std::string arr[3] = {"Presidential", "Robotomy", "Shrubbery"};
	int i = 0;
	for(; i < 3 ; i++)
	{
		if (arr[i] == n)
			break;
	}
	switch(i)
	{
		case 0:
			std::cout << "Intern creates " << t << std::endl;
			return (new PresidentialPardonForm(t));
		case 1:
			std::cout << "Intern creates " << t << std::endl;
			return (new RobotomyRequestForm(t));
		case 2:
			std::cout << "Intern creates " << t << std::endl;
			return (new ShrubberyCreationForm(t));
		case 3:
			throw std::invalid_argument("Invalid name: " + n + "- valid names are Presidential, Robotomy, Shrubbery \n");
	}
	return (NULL);
}

