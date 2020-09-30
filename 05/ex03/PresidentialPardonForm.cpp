/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 21:43:02 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/29 19:56:53 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string new_target) :
	Form("Presidential Pardon Form", 25, 5),
	target(new_target)
{
	srand (time(NULL));
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) :
	Form("Presidential Pardon Form", 25, 5),
	target(copy.target)
{
	
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &operand)
{
	this->target = operand.target;
	return (*this);
}


void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{	
	Form::execute(executor);

	// His name is actually Zaphod, but....
	std::cout << this->target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

Form *PresidentialPardonForm::create(std::string target)
{
	return new PresidentialPardonForm(target);
}