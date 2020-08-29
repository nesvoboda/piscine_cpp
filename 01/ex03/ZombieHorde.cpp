/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 15:35:01 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/27 16:05:33 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N)
{
	this->N = N;
	
	// Initialize the Random number generator
	std::srand(time(NULL));
	
	// Here's our pool of names
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

	// Allocate memory for our zombies
	this->storage = new Zombie[N];

	// Give names to zombies
	for (int i = 0; i < N; i++)
	{
		storage[i].setName(names[rand() % 10]);
	}

}

ZombieHorde::~ZombieHorde(void)
{
	// Free the whole array
	delete [] this->storage;
}

void ZombieHorde::announce(void)
{
	for (int i = 0; i < this->N; i++)
	{
		this->storage[i].announce();
	}
}