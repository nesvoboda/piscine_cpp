/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 19:12:04 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/26 19:53:57 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string new_name, unsigned int new_grade) : 
	name(new_name), grade(new_grade)
{
	if (new_grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	if (new_grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy):
	name(copy.name), grade(copy.grade)
{
}

Bureaucrat &Bureaucrat::operator= (const Bureaucrat &operand)
{
	// Name is constant, so even assignment won't change it.
	this->grade = operand.getGrade();
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return this->name;
}

unsigned int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::incrementGrade(unsigned int i)
{
	if (this->grade - i < 1 || i > 150)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	this->grade -= i;
}

void Bureaucrat::decrementGrade(unsigned int i)
{
	if (this->grade + i > 150 || i > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	this->grade += i;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException:: what() const throw()
{
	return ("Grade is too low!");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}