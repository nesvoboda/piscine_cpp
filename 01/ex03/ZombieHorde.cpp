/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 15:35:01 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/26 16:29:45 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N)
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
	this->storage = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		storage[i].setName(names[rand() % 10]);
	}

}

ZombieHorde::~ZombieHorde(void)
{
	delete this->storage;
}

ZombieHorde::announce(void)
{
	
}