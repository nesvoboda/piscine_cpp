/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 12:48:27 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/29 19:26:32 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string new_target) :
	Form("Robotomy Request Form", 72, 45),
	target(new_target)
{
	srand (time(NULL));
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) :
	Form("Robotomy Request Form", 72, 45),
	target(copy.target)
{
	
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &operand)
{
	this->target = operand.target;
	return (*this);
}


void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{	
	Form::execute(executor);

	int success = rand() % 2;
	
	if (success == 1)
	{
		std::cout << "Brr brr brr... " << this->target << " has been robotomized successfully" << std::endl;
	}
	else
	{
		std::cout << "[ERROR] The robotomy of " << this->target << " has been a failure." << std::endl;
	}
}
