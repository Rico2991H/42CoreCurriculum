#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
hitPoints(0),
energyPoints(0),
attackDamage(0),
Name("noName")
{

}

ClapTrap::ClapTrap(std::string input) : 
hitPoints(0),
energyPoints(0),
attackDamage(0),
Name("noName")
{
	std::cout << "ClapTrap Constructor called for " << input << std::endl;
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

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called\n";
}

ClapTrap& 	ClapTrap::operator=(const ClapTrap& other)
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

void 		ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap" << Name << "attacks" << target << "causing" << attackDamage << "points of damage!\n";
	energyPoints--;
}
void 		ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap" << Name << "suffers an attack, causing" << amount << "points of damage!\n";
	hitPoints -= amount;
}
void 		ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap" << Name << "is being repaired, restoring" << amount << "of hit points!\n";
	energyPoints--;
	hitPoints += amount;
}

std::string	ClapTrap::getName() { return(Name); } const;

int			ClapTrap::getHitPoints() { return(hitPoints); } const;

int			ClapTrap::getAttackDamage() { return(attackDamage); } const;

void		ClapTrap::setName(std::string input)
{
	Name = input;
}

void		ClapTrap::setEnergyPoints(int nb)
{
	energyPoints = nb;
}

void		ClapTrap::setHitPoints(int nb)
{
	hitPoints = nb;
}
void		ClapTrap::setAttackDamage(int nb)
{
	attackDamage = nb;
}