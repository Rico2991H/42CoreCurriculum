/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoogend <rhoogend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:28:26 by rhoogend          #+#    #+#             */
/*   Updated: 2026/08/05 12:43:24 by rhoogend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

void	tryExecute(AForm* A, const Bureaucrat& Bc)
{
	try
	{
		A->execute(Bc);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

void	trySignForm(AForm* A, const Bureaucrat& Bc)
{
	try
	{
		Bc.signForm(*A);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	
}

int main()
{
	Intern		Worker;
	Bureaucrat	Bc1(145, "Alfred");
	Bureaucrat	Bc2(71, "George");
	Bureaucrat	Bc3(2, "Promo");
	Bureaucrat Ar[3] = {Bc1, Bc2, Bc3};
	AForm		*Pf = NULL;
	AForm		*Rf = NULL;
	AForm		*Sf = NULL;
	/*PresidentialPardonForm	Pf("PPForm");
	RobotomyRequestForm		Rf("RRForm");
	ShrubberyCreationForm	Sf("SCForm");*/
	try
	{
		Pf = Worker.makeForm("Presidential", "Benzo");
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		Rf = Worker.makeForm("Robotomy", "Cris");
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		Sf = Worker.makeForm("Shrubbery", "Rico");
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	AForm* 		F[3] = {Pf,Rf,Sf};	
	for (int i = 0; i < 3; i++)
	{
		tryExecute(F[i], Ar[i]);
	}
	for ( int i = 0; i < 3; i++)
	{
		trySignForm(F[i], Ar[i]);
	}
	for (int i = 0; i < 3; i++)
	{
		tryExecute(F[i], Ar[i]);
	}
	delete Sf;
	delete Rf;
	delete Pf;
}