#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>
class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string input);
		~FragTrap();
		void highFivesGuys(void);
	private:
};

#endif
