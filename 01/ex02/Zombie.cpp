/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 14:11:55 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/26 15:35:52 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type)
{
	this->name.assign(name);
	this->type.assign(type);
}

void	Zombie::announce(void)
{
	std::cout << "<" << this->name << " (" << this->type << ")> "
	<< "Braiiiiiiinnnssss..." << std::endl;
}
