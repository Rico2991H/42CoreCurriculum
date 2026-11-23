#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm(145, 137, "SCFORM")
{
	std::cout << "Constructor called\n";
	this->setTarget("default");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string t)
: AForm(145, 137, "SCFORM")
{
	std::cout << "Constructor called\n";
	this->setTarget(t);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: AForm(145, 137, "SCFORM")
{
	std::cout << "Copy consturctor called\n";
	this->setTarget(other.getTarget());
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << "Copy assignment operator called\n";
	if(this != &other)
	{
		this->setTarget(other.getTarget());
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Destructor called\n";
}

void	ShrubberyCreationForm::CreateFile()
{
	std::ofstream XFile((this->getTarget() + "_shrubbery").c_str());
	XFile << "   * *    " << std::endl;
	XFile << "  ** **   " << std::endl;
	XFile << " *******  " << std::endl;
	XFile << " *******  " << std::endl;
	XFile << "  *****   " << std::endl;
	XFile << "    *    	" << std::endl;
	XFile << " *  *  *  " << std::endl;
	XFile << "  * * *   " << std::endl;
	XFile << "   ***    " << std::endl;
	XFile.close();
}

void	ShrubberyCreationForm::execute(const Bureaucrat &e)
{
	AForm::execute(e);
	this->CreateFile();
}