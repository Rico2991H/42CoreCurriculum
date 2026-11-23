#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(int s_grade, int e_grade, std::string n);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();
		void 		checkGrade(int val);
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
		class NotSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		std::string			getName() const;
		std::string			getTarget() const;
		void				setTarget(std::string t);
		int					get_Sgrade() const;
		int					get_Egrade() const;
		bool				get_Sign() const;
		void				beSigned(const Bureaucrat& s);
		virtual void		execute(const Bureaucrat& e) = 0;
	private:
		std::string const	name;
		std::string 		target;
		int const			sign_grade;
		int const			exec_grade;
		bool				sign;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
