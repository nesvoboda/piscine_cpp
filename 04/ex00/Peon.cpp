/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 15:05:13 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/13 18:13:28 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

Peon::Peon(std::string new_name) : Victim(new_name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(const Peon &copy) : Victim(copy)
{
}

Peon& Peon::operator= (const Peon &operand)
{
	Victim::operator=(operand);
	return (*this);
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

void Peon::getPolymorphed(void) const
{
	std::cout << this->getName() << " has been turned into a pink pony!"
	<< std::endl;
}
