#include "Form.hpp"
#include "Bureaucrat.hpp"

// Constructors

Form::Form()
: name("default"), sign_grade(1), exec_grade(1), sign(false)
{
	std::cout << "Def constructor called\n";
}

Form::Form(int s_grade, int e_grade, std::string n) 
: name(n), sign_grade(s_grade), exec_grade(e_grade), sign(false)
{
	checkGrade(e_grade);
	checkGrade(s_grade);
	std::cout << "Constructor called\n";
}

Form::Form(const Form& other)
: name(other.getName()), sign_grade(other.get_Sgrade()), exec_grade(other.get_Egrade()), sign(other.get_Sign())
{
	std::cout << "Copy consturctor called\n";
}

//destructor

Form::~Form()
{
    std::cout << "Destructor called\n";
}

//overloaded operators

Form& Form::operator=(const Form& other)
{
	std::cout << "Copy assignment operator called\n";
	if(this == &other)
	{
		return (*this);
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << "Form: " << f.getName() << std::endl
	<< "Sign grade: " << f.get_Sgrade() << std::endl
	<< "Execution grade: " << f.get_Egrade() << std::endl
	<< "Sign status: " << f.get_Sign() << std:: endl;
	return (os);
}

// getters

std::string			Form::getName() const
{
	return (name);
}
int					Form::get_Sgrade() const
{
	return (sign_grade);
}

int					Form::get_Egrade() const
{
	return (exec_grade);
}

bool				Form::get_Sign() const
{
	return (sign);
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

void		Form::checkGrade(int val)
{
	if (val < 1)
		throw GradeTooHighException();
	if (val > 150)
		throw GradeTooLowException();
}

void		Form::beSigned(const Bureaucrat& Bc)
{
	if (Bc.getGrade() < this->get_Sgrade())
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