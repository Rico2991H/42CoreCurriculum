/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoogend <rhoogend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:34:48 by rhoogend          #+#    #+#             */
/*   Updated: 2026/03/19 11:28:20 by rhoogend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string str1)
{
    setType(str1);
}

Weapon::~Weapon()
{
}

const std::string& Weapon::getType() const {return (type);}

void        Weapon::setType(std::string input)
{
    type = input;
}
