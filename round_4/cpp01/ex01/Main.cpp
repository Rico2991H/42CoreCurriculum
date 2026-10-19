/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoogend <rhoogend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:02:28 by rhoogend          #+#    #+#             */
/*   Updated: 2026/03/17 15:49:09 by rhoogend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>
#include <iostream>

int main()
{
	int	n = 7;
    std::string name = "igor";
    std::string name2 = "stein";
	Zombie *horde = ZombieHorde( name2, n);
	delete[] horde;
    return (0);
}