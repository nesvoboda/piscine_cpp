/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:21:00 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/04 18:07:32 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Human.hpp"

int main(void)
{

	// The subject main
	Human bob;
	std::cout << bob.identify() << std::endl;
	std::cout << bob.getBrain().identify() << std::endl;

	// Some other things to test out Brain and Human
	Brain randomBrain;
	std::cout << "The randomBrain's IQ is: " << randomBrain.getIQ() << std::endl;
	std::cout << "The randomBrain's Volume is: " << randomBrain.getVolume() << std::endl;

	Human randomHuman;
	const Brain &randomHumansBrain = randomHuman.getBrain();
	std::cout << "The randomHumansBrain's IQ is: " << randomHumansBrain.getIQ() << std::endl;
	std::cout << "The randomHumansBrain's Volume is: " << randomHumansBrain.getVolume() << std::endl;
}
