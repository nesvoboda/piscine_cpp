/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 14:18:18 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/26 20:13:34 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <exception>
# include <iostream>

class Form;

class Bureaucrat {

public:
	Bureaucrat(std::string name, unsigned int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator= (const Bureaucrat &operand);

	std::string getName() const;
	unsigned int getGrade() const;
	void incrementGrade(unsigned int i);
	void decrementGrade(unsigned int i);
	
	void signForm(Form &f);

	class GradeTooHighException: public std::exception {
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException: public std::exception {
		public:
			virtual const char* what() const throw();
	};

private:
	Bureaucrat();
	const std::string	name;
	unsigned int		grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif