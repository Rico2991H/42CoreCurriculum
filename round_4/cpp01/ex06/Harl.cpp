/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoogend <rhoogend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 11:44:21 by rhoogend          #+#    #+#             */
/*   Updated: 2026/03/19 16:54:43 by rhoogend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

Harl::Harl()
{
}

Harl::~Harl()
{
}

void    Harl::debug(void)
{
	std::cout << "DEBUG:" << "I love some Nasi goreng" << std::endl; 	
}

void    Harl::info(void)
{
	std::cout << "INFO:" << "I can't believe there is no Sambal, I need more sambal" << std::endl;	
}

void    Harl::warning(void)
{
	std::cout << "WARINING:" << "I think you should start making sambal, its not nice without the spice" << std::endl;
}

void    Harl::error(void)
{
	std::cout << "ERROR:" << "DEATH BY SAMBAL" << std::endl;	
}

void    Harl::complain(std::string level)
{
	int		i = 0;
	void	(Harl::*ptrtoFunc[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	std::string levels[] = { "debug", "info", "warning", "error"};

	while (level != levels[i] && i < 4)
		i++;
	if (i == 4)
		std::cout << "Propbably complaining about insignificant problems \n";
	for (;i < 4; i++)
	{
		switch(i)
		{
			case 0:
			{
				(this->*ptrtoFunc[i])();
				break;
			}
			case 1:
			{
				(this->*ptrtoFunc[i])();
				break;
			}
			case 2:
			{
				(this->*ptrtoFunc[i])();
				break;
			}
			case 3:
			{
				(this->*ptrtoFunc[i])();
				break;
			}
		}
	}
			
}