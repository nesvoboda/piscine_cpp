/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 10:58:35 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/23 13:36:02 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fire.hpp"

Fire::Fire() : AMateria("fire")
{
}

Fire::Fire(const Fire &copy) : AMateria(copy)
{
}

Fire & Fire::operator= (const Fire &operand)
{
	AMateria::operator=(operand);
	return (*this);
}

Fire::~Fire()
{
}

AMateria* Fire::clone() const
{
	Fire *newFire = new Fire(*this);
	return newFire;
}

void Fire::use(ICharacter& target)
{
	AMateria::use(target);
	std::cout << "* shoots a fireball at " << target.getName() << " *" << std::endl;
}
