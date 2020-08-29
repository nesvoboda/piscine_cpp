/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 17:45:47 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/29 13:26:50 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type.assign(type);
}

const std::string	&Weapon::getType(void)
{
	return this->type;
}

const void			Weapon::setType(std::string type)
{
	this->type.assign(type);
}