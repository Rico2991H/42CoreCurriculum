#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Constructors

AForm::AForm()
: name("default"), sign_grade(1), exec_grade(1), sign(false)
{
	std::cout << "Def constructor called\n";
}

AForm::AForm(int s_grade, int e_grade, std::string n) 
: name(n), sign_grade(s_grade), exec_grade(e_grade), sign(false)
{
	checkGrade(e_grade);
	checkGrade(s_grade);
	std::cout << "Constructor called\n";
}

AForm::AForm(const AForm& other)
: name(other.getName()), sign_grade(other.get_Sgrade()), exec_grade(other.get_Egrade()), sign(false)
{
	std::cout << "Copy consturctor called\n";
}

//destructor

AForm::~AForm()
{
    std::cout << "Destructor called\n";
}

//overloaded operators

AForm& AForm::operator=(const AForm& other)
{
	std::cout << "Copy assignment operator called\n";
	if(this != &other)
	{
		this->sign = other.sign;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << "AForm: " << f.getName() << std::endl
	<< "Sign grade: " << f.get_Sgrade() << std::endl
	<< "Execution grade: " << f.get_Egrade() << std::endl
	<< "Sign status: " << f.get_Sign() << std:: endl;
	return (os);
}

// getters

std::string			AForm::getName() const
{
	return (name);
}
int					AForm::get_Sgrade() const
{
	return (sign_grade);
}

int					AForm::get_Egrade() const
{
	return (exec_grade);
}

bool				AForm::get_Sign() const
{
	return (sign);
}

std::string			AForm::getTarget() const
{
	return (target);
}

//setters

void				AForm::setTarget(std::string t)
{
	this->target = t;
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* AForm::NotSignedException::what() const throw()
{
	return ("Form is not signed");
}

void		AForm::checkGrade(int val)
{
	if (val < 1)
		throw GradeTooHighException();
	if (val > 150)
		throw GradeTooLowException();
}

void		AForm::beSigned(const Bureaucrat& Bc)
{
	if (Bc.getGrade() <= this->get_Sgrade())
	{
		this->sign = true;
		std::cout << Bc.getName() << " signed " << this->getName() << std::endl;
	}
	else
	{
		std::cout << Bc.getName() << " couldn't sign " << this->getName() <<
		" because "; 
		throw GradeTooLowException();
	} 
}

void		AForm::execute(const Bureaucrat& e)
{
	if (!this->get_Sign())
	{
		std::cout << e.getName() << " couldn't execute " << this->getName() <<
		" because "; 
		throw NotSignedException();		
	}
	else if (e.getGrade() <= this->get_Egrade())
		std::cout << e.getName() << " executed " << this->getName() << std::endl;
	else
	{
		std::cout << e.getName() << " couldn't execute " << this->getName() <<
		" because "; 
		throw GradeTooLowException();
	} 
}