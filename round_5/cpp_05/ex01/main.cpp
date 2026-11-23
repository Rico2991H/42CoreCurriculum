/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoogend <rhoogend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:28:26 by rhoogend          #+#    #+#             */
/*   Updated: 2026/06/11 12:51:20 by rhoogend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Form file1(10, 15, "file1");
	Bureaucrat Bc(4, "Alfred");
	Bureaucrat Bc2(20, "Intern");

	std::cout << Bc;
	std::cout << Bc2;
	std::cout << file1;
	try
	{
		Bc.signForm(file1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bc2.signForm(file1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}