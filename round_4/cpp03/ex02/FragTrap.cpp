/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoogend <rhoogend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:04:08 by rhoogend          #+#    #+#             */
/*   Updated: 2026/03/26 16:05:33 by rhoogend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <string>
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
	setAttackDamage(30);	
	setEnergyPoints(100);
	setHitPoints(100);
	std::cout << "FragTrap Def Contructor called for <<" << this->getName() << "\n";
}

FragTrap::FragTrap(std::string input) : 
ClapTrap(input) 
{
	setAttackDamage(30);
	setEnergyPoints(100);
	setHitPoints(100);
	std::cout << "FragTrap Constructor called for " << this->getName() << "\n";
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
	std::cout << "FragTrap Copy Constructor called" << std::endl;
}
FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called\n";
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
    if (this != &src)
    {
        ClapTrap::operator=(src);
    }
    return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "Hey! High Five!" << std::endl;	
}