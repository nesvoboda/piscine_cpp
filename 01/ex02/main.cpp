/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 14:11:55 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/26 15:30:02 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

int main(void)
{
	std::cout << "First, let's create a zombie on the stack"
	<< " and see if it works" << std::endl;
	Zombie stackZombie("Alan Turing", "A geek zombie");
	stackZombie.announce();
	std::cout << "mr.Turing will be destroyed as soon as the variable"
	" stackZombie goes out of scope." << std::endl;

	ZombieEvent zombieGenerator;

	zombieGenerator.setZombieType("A hungry zombie");

	std::cout << "Now let's create a random zombie (on the stack)" << std::endl;

	zombieGenerator.randomChump();

	std::cout << "In another test, we create a new zombie on the heap using"
	<< " ZombieEvent::newZombie" << std::endl;

	Zombie *heapZombie = zombieGenerator.newZombie("John Doe");
	heapZombie->announce();

	std::cout << "Now let's delete it to avoid a memory leak" << std::endl;
	delete heapZombie;
}