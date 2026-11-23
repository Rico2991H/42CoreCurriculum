/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoogend <rhoogend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 10:03:27 by rhoogend          #+#    #+#             */
/*   Updated: 2026/08/05 11:09:49 by rhoogend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>



class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(int grade, std::string n);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
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
		std::string 	getName() const;
		int				getGrade() const;
		static void		checkGrade(int val);
		void			Increment();
		void			Decrement();

	private:
		int	grade;
		std::string const name;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
#endif
