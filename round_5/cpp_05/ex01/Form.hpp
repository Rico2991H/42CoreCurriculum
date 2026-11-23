#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(int s_grade, int e_grade, std::string n);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();
		void 				checkGrade(int val);
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		std::string			getName() const;
		int					get_Sgrade() const;
		int					get_Egrade() const;
		bool				get_Sign() const;
		void				beSigned(const Bureaucrat&);

	private:
		std::string const	name;
		int const			sign_grade;
		int const			exec_grade;
		bool				sign;
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif
