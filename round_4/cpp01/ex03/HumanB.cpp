/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoogend <rhoogend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 11:26:01 by rhoogend          #+#    #+#             */
/*   Updated: 2026/03/19 11:26:04 by rhoogend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string input1)
{
    name = input1;
}

HumanB::~HumanB()
{
}

void    HumanB::setWeapon(const Weapon& club)
{
    Tool2 = &club;
}

void    HumanB::attack()
{
    std::cout << name << "attacks with their" << Tool2->getType() << std::endl;
}