/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:46:55 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/27 16:04:19 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"
#include <unistd.h>

void	create_a_horde_and_announce(int N)
{
	// Create a new ZombieHorde on the stack
	// (so every bad allocation is my fault)
	ZombieHorde horde(N);

	// Invoke its functionality
	horde.announce();
}

int main(void)
{
	std::cout << "Let's create a zombie horde of 5 zombies"
	<< std::endl;

	// We create the horde in a separate function
	// so that it reliably goes out of scope and
	// is deleted
	create_a_horde_and_announce(5);

	// You can check for leaks to see if I have freed
	// all the memory used to store zombies
	std::cout << "Now you have 50 seconds to check for leaks"
	<< std::endl;
	sleep(50);
	return 0;
}