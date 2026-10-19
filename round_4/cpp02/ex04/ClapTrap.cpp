#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string input)
{
	std::cout << "Constructor called\n";
	Name = input;
}

ClapTrap::ClapTrap(const ClapTrap& other) 
	: 	Name(other.Name), 
		hitPoints(other.hitPoints), 
		energyPoints(other.energyPoints),
		attackDamage(other.attackDamage) 
{
	std::cout << "Copy consturctor called\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Copy assignment operator called\n";
	if(this != &other)
	{
		attackDamage = other.attackDamage;
		energyPoints = other.energyPoints;
		hitPoints = other.hitPoints;
		Name = other.Name;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap" << Name << "attacks" << target << "causing" << attackDamage << "points of damage!\n";
}
void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap" << Name << "suffers an attack causing" << amount << "points of damage!\n";
}
void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap" << Name << "is being repaired, restoring" << amount << "of energyPoints!\n";
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called\n";
}
