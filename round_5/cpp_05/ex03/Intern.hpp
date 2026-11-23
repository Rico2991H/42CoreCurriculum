#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();
		AForm* makeForm(std::string n, std::string t);
	private:

};

#endif
