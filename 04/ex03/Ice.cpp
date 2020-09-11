/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 10:58:35 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/06 12:35:57 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(const Ice &copy) : AMateria(copy.getType())
{
}

Ice & Ice::operator= (const Ice &operand)
{
	AMateria::operator=(operand);
	return (*this);
}

Ice::~Ice()
{
}

AMateria* Ice::clone() const
{
	Ice *newIce = new Ice(*this);
	return newIce;
}

void Ice::use(ICharacter& target)
{
	this->incrementXp();
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
