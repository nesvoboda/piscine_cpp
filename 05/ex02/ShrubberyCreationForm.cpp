/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 21:44:27 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/29 19:26:30 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string new_target) :
	Form("Shrubbery Creation form", 145, 137),
	target(new_target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) :
	Form(copy),
	target(copy.target)
{
	
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &operand)
{
	Form::operator=(operand);
	this->target = operand.target;
	return (*this);
}

const char* ShrubberyCreationForm::FileErrorException::what() const throw()
{
	return "File error while executing ShrubberyCreationForm";
}


void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{	
	Form::execute(executor);
	
	std::ofstream fs;
	std::string filename;
	filename = this->target + "_shrubbery";
	fs.open (filename);

	if (!fs.is_open())
		throw FileErrorException();
	
	for (int i = 0; i < 3; i++)
	{
		fs <<	"      /\\      " << std::endl
		<<	"     /\\*\\     " << std::endl
		<<	"    /\\O\\*\\    " << std::endl
		<<	"   /*/\\/\\/\\   " << std::endl
		<<	"  /\\O\\/\\*\\/\\  " << std::endl
		<<	" /\\*\\/\\*\\/\\/\\ " << std::endl
		<<	"/\\O\\/\\/*/\\/O/\\" << std::endl
		<<	"      ||      " << std::endl
		<<	"      ||      " << std::endl
		<<	"      ||      " << std::endl;

		fs << std::endl;
	}
	
	fs.close();
	
}