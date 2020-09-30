/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 20:11:19 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/29 12:30:29 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string new_name, unsigned int new_gradeToSign, unsigned int new_gradeToExecute) :
	name(new_name),
	gradeToSign(new_gradeToSign),
	gradeToExecute(new_gradeToExecute),
	isSigned(false)
{
	if (new_gradeToExecute < 1 || new_gradeToSign < 1)
		throw Form::GradeTooHighException();
	if(new_gradeToExecute > 150 || new_gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::~Form()
{
}

Form::Form(const Form &copy) :
	name(copy.name),
	gradeToSign(copy.gradeToSign),
	gradeToExecute(copy.gradeToExecute),
	isSigned(copy.isSigned)
{
}

Form &Form::operator= (const Form &operand)
{
	// Name and grades are costant
	this->isSigned = operand.getIsSigned();
	return (*this);
}

std::string Form::getName() const
{
	return this->name;
}

bool Form::getIsSigned() const
{
	return this->isSigned;
}

unsigned int Form::getGradeToSign() const
{
	return this->gradeToSign;
}

unsigned int Form::getGradeToExecute() const
{
	return this->gradeToExecute;
}

void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->gradeToSign)
		throw Form::GradeTooLowException();
	this->isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char* Form::FormNotSignedException::what() const throw()
{
	return "The form hasn't been signed yet, can't execute.";
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << f.getName() << ", form, grade to sign: " << f.getGradeToSign() << ", grade to execute: " << f.getGradeToExecute();
	return os;
}

void Form::execute(Bureaucrat const &executor) const
{
	if (!this->isSigned)
	{
		throw FormNotSignedException();
	}
	if (this->gradeToExecute < executor.getGrade())
	{
		throw GradeTooLowException();
	}
}