/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoogend <rhoogend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:28:26 by rhoogend          #+#    #+#             */
/*   Updated: 2026/08/06 12:03:15 by rhoogend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	int 		grade1 = 149;
	int 		grade2 = 160;
	int 		grade3 = -10;
	Bureaucrat 	Bc;
	try
	{
		Bureaucrat Bc2(grade1, "Bc2");
		std::cout << Bc2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		
	}
	try
	{
		Bureaucrat Bc3(grade2, "Bc3");
		std::cout << Bc3 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat Bc4(grade3, "Bc4");
		std::cout << Bc4 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bc.Increment();	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bc.Increment();	
	}	
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}