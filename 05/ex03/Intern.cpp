/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 19:10:55 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/29 20:19:18 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const std::string Intern::labels[3] = {
	"ShrubberyCreationForm",
	"RobotomyRequestForm",
	"PresidentialPardonForm",
};

Form *(* const Intern::functions[3])(std::string) =
{
	ShrubberyCreationForm::create,
	RobotomyRequestForm::create,
	PresidentialPardonForm::create,
};

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &copy)
{
	(void) copy;
}

Intern &Intern::operator= (const Intern &operand)
{
	(void) operand;
	return (*this);
}

Form *Intern::makeForm(std::string label, std::string target)
{
	for (int i = 0; i < 3; i++)
	{
		if (labels[i] == label)
		{
			return functions[i](target);
		}
	}
	return nullptr;
}

