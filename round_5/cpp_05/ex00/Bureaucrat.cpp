/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoogend <rhoogend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 10:03:18 by rhoogend          #+#    #+#             */
/*   Updated: 2026/08/07 13:28:57 by rhoogend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : grade(1), name("default") 
{
	std::cout << "Default constructor called\n";
}

Bureaucrat::Bureaucrat(int val, std::string n) : name(n)
{
	std::cout << "Constructor called\n";
	checkGrade(val);
	this->grade = val;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name)
{
	std::cout << "Copy constructor called\n";
	this->grade = other.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Copy assignment operator called\n";
	if(this != &other)
	{
		this->grade = other.grade;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << " bureaucrat grade " << b.getGrade() << std::endl;
	return (os);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called\n";
}

std::string Bureaucrat::getName() const
{
	return (this->name);
}

int			Bureaucrat::getGrade() const
{
	return (this->grade);
}

void		Bureaucrat::Increment()
{
	checkGrade(grade -1);
	grade--;
}

void		Bureaucrat::Decrement()
{
	checkGrade(grade + 1);
	grade++;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

void		Bureaucrat::checkGrade(int val)
{
	if (val < 1)
		throw GradeTooHighException();
	if (val > 150)
		throw GradeTooLowException();
}