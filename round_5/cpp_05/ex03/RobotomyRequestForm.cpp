#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
: AForm(72, 45, "RRFORM")
{
	std::cout << "Def constructor called\n";
	this->setTarget("default");
}

RobotomyRequestForm::RobotomyRequestForm(std::string t)
: AForm(72, 45, "RRFORM") 
{
	std::cout << "Constructor called\n";
	this->setTarget(t);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: AForm(72, 45, "RRFORM")
{
	std::cout << "Copy consturctor called\n";
	this->setTarget(other.getTarget());
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	std::cout << "Copy assignment operator called\n";
	if(this != &other)
	{
		this->setTarget(other.getTarget());
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Destructor called\n";
}

void	RobotomyRequestForm::convRobotomy()
{
	std::cout << " BBBRRRRRbbbbbrrrrrrBBBBBRRRRR" << std::endl;
	if (rand() % 2)
		std::cout << getTarget() << " has been robotomized" << std::endl;
	else
		std::cout << getTarget() << " Went to the next world" << std::endl;
}

void	RobotomyRequestForm::execute(const Bureaucrat &e)
{
	AForm::execute(e);
	this->convRobotomy();
}