#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
}

ScavTrap::ScavTrap(std::string input) : 
ClapTrap(input) 
{
	setAttackDamage(20);
	setEnergyPoints(50);
	setHitPoints(100);
	std::cout << "ScavTrap Constructor called\n";
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	if (this != &src)
	{
		ClapTrap::operator=(src);
	}
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
    std::cout << "ScavTrap " << getName()
              << " attacks " << target
              << ", causing " << getAttackDamage()
              << " points of damage!\n";
	this->setEnergyPoints(-1);
}

void ScavTrap::guardGate()
{
	std::cout << getName() << " is now in Gate keeper mode.\n";
}