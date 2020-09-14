/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OldRifle.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 13:33:41 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/14 13:33:42 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OldRifle.hpp"

OldRifle::OldRifle(): AWeapon("Power Fist", 8, 50)
{
}

OldRifle::OldRifle(const OldRifle &copy) :
	AWeapon(copy)
{
}

OldRifle & OldRifle::operator= (const OldRifle &operand)
{
	AWeapon::operator=(operand);
	return (*this);
}

OldRifle::~OldRifle()
{
}

void OldRifle::attack() const
{
	std::cout << "* BANG! *" << std::endl;
}