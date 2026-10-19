/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoogend <rhoogend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 11:44:21 by rhoogend          #+#    #+#             */
/*   Updated: 2026/03/19 15:01:19 by rhoogend         ###   ########.fr       */
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
	void	(Harl::*ptrtoFunc[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	std::cout << "this is the input" << level << std::endl;
	std::string levels[] = { "debug", "info", "warning", "error"};
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*ptrtoFunc[i])();
			return;
		}
	}
			
}