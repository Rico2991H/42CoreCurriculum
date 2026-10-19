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
		void 		attack(const std::string& target);
		void 		takeDamage(unsigned int amount);
		void 		beRepaired(unsigned int amount);
		void		setEnergyPoints(int nb);
		void		setHitPoints(int nb);
		void		setAttackDamage(int nb);
		int			getAttackDamage();
		std::string	getName();
		~ClapTrap();

	private:
		std::string Name;
		int			hitPoints;
		int			energyPoints;
		int			attackDamage;

};

#endif
