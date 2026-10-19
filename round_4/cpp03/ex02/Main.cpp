/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoogend <rhoogend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 10:49:57 by rhoogend          #+#    #+#             */
/*   Updated: 2026/03/26 15:18:02 by rhoogend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	std::string input = "Charizard";
	ScavTrap ScavTrap("Harry");
	FragTrap FragTrap("Bert");
	ScavTrap.attack(input);
	ScavTrap.guardGate();
	FragTrap.highFivesGuys();
}
