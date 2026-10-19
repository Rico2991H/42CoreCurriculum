/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoogend <rhoogend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:26:12 by rhoogend          #+#    #+#             */
/*   Updated: 2026/03/17 15:49:53 by rhoogend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>
#include <iostream>

Zombie::Zombie()
{ 
}

Zombie::~Zombie()
{
    std::cout << "Destroyed:";
}

void Zombie::setName(std::string input)
{
    name = input;   
}

std::string Zombie::getName() {return name;}

void    Zombie::announce( void )
{
    std::cout << name << ":" << "BraiiiiiiinnnzzzZ..." << std::endl;
}
