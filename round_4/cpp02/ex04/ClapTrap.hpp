#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>
#include <iostream>

class ClapTrap
{
	public:
		ClapTrap(std::string input);
		ClapTrap(const ClapTrap& other);
		ClapTrap& 	operator=(const ClapTrap& other);
		void 		ClapTrap::attack(const std::string& target);
		void 		ClapTrap::takeDamage(unsigned int amount);
		void 		ClapTrap::beRepaired(unsigned int amount);
		
		~ClapTrap();

	private:
		std::string Name;
		int			hitPoints;
		int			energyPoints;
		int			attackDamage;

};

#endif
