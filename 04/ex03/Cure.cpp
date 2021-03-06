/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 10:58:35 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/23 13:22:32 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure &copy) : AMateria(copy)
{
}

Cure & Cure::operator= (const Cure &operand)
{
	AMateria::operator=(operand);
	return (*this);
}

Cure::~Cure()
{
}

AMateria* Cure::clone() const
{
	Cure *newCure = new Cure(*this);
	return newCure;
}

void Cure::use(ICharacter& target)
{
	// this->incrementXp();
	AMateria::use(target);
	std::cout << "* heals " << target.getName() << "’s wounds * " << std::endl;
}