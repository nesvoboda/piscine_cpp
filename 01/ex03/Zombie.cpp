/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 14:11:55 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/05 08:34:18 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type)
{
	this->name.assign(name);
	this->type.assign(type);
}

Zombie::Zombie(void)
{
	this->name.assign("John Doe");
	this->type.assign("Ordinary Zombie");
}

void	Zombie::announce(void)
{
	std::cout << "<" << this->name << " (" << this->type << ")> "
	<< "Braiiiiiiinnnssss..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name.assign(name);
}

void	Zombie::setType(std::string type)
{
	this->type.assign(type);
}