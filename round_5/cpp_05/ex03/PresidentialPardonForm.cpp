#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <string>

PresidentialPardonForm::PresidentialPardonForm()
: AForm(25, 5, "PPFORM")
{
	std::cout << "Constructor called\n";
	this->setTarget("default");
}

PresidentialPardonForm::PresidentialPardonForm(std::string t)
: AForm(25, 5, "PPFORM")
{
	std::cout << "Constructor called\n";
	this->setTarget(t);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
: AForm(25, 5, "PPFORM")
{
	std::cout << "Copy consturctor called\n";
	this->setTarget(other.getTarget());
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	std::cout << "Copy assignment operator called\n";
	if(this != &other)
	{
		this->setTarget(other.getTarget());
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Destructor called\n";
}

void	PresidentialPardonForm::Perform_PP()
{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
void	PresidentialPardonForm::execute(const Bureaucrat &e)
{
	AForm::execute(e);
	Perform_PP();
}
