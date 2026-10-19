/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoogend <rhoogend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:32:00 by rhoogend          #+#    #+#             */
/*   Updated: 2026/03/17 16:32:01 by rhoogend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
    private:
        std::string name;

    public:
        void        announce( void );
                    Zombie();
        std::string getName();
        void        setName(std::string input);
                    ~Zombie();

};

Zombie *newZombie( std::string name );
Zombie *ZombieHorde( std::string name, int N);

#endif
