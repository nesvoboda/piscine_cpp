/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 14:11:55 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/04 17:50:32 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent()
{
	this->zombieType.assign("Ordinary Zombie");
}

void ZombieEvent::setZombieType(std::string type)
{
	this->zombieType.assign(type);
}

void ZombieEvent::randomChump(void)
{
	std::srand(time(NULL));
	std::string names[10] = {
		"Roberta Finney",
		"Keiren Howell",
		"Garfield Cartwright",
		"Umayr Tanner",
		"Lylah Thorpe",
		"Derek Meadows",
		"Ellie-Louise Boone",
		"Albi Moreno",
		"Emmie Ferreira",
		"Ali Broughton",
	};

	Zombie chump(names[std::rand() % 10], this->zombieType);
	chump.announce();
}

Zombie *ZombieEvent::newZombie(std::string name)
{
	Zombie *ret;

	ret = new Zombie(name, this->zombieType);
	return ret;
}
