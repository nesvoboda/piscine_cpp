/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 10:58:35 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/16 20:19:56 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

// Sleep
#include <unistd.h>

// Needed to automatically fail tests;
#include <assert.h>

int test_no = 1;

void out(std::string s)
{
	std::cout << std::endl;
	std::cout << "\033[0;34m" << "Test " << test_no << " | " << s << "\033[0m" << std::endl;
	test_no += 1;
}

void eo(std::string s)
{
	std::cout << "\33[1;33m" << "Expected output:" <<"\033[0m" << std::endl;
	std::cout << s << std::endl;
}

void check(int expression)
{
	// If expression doesn't evaluate to 1, the program will abort
	assert(expression == 1);
	std::cout << "\033[92m✓ PASS\033[0m" << std::endl;
}


int main()
{
	{	
		std::cout << "\nSubject tests\n\n";
		{
			IMateriaSource* src = new MateriaSource();
			src->learnMateria(new Ice());
			src->learnMateria(new Cure());
			ICharacter* me = new Character("me");
			AMateria* tmp;
			tmp = src->createMateria("ice");
			me->equip(tmp);
			tmp = src->createMateria("cure");
			me->equip(tmp);
			ICharacter* bob = new Character("bob");
			me->use(0, *bob);
			me->use(1, *bob);
			delete bob;
			delete me;
			delete src;
			return 0;
		}
		std::cout << "\nAdditional tests\n\n";
		
		out("Ice | Constructor");
		Ice i1 = Ice();
		check(i1.getType() == "ice");
		check(i1.getXP() == 0);

		out("Ice | Copy constructor");
		Ice i2 = Ice(i1);
		check(i2.getType() == "ice");
		check(i2.getXP() == 0);

		out("Ice | Assignment operator");
		Ice i3 = Ice();
		check(i3.getType() == "ice");
		check(i3.getXP() == 0);

		i3 = i2;

		check(i3.getType() == "ice");
		check(i3.getXP() == 0);

		out("Ice | Destructor");
		{
			Ice i4 = Ice();
		}
		
		out("Ice | use modifies xp");
		Character dummy = Character("Dummy");
		i3.use(dummy);
		check(i3.getXP() == 10);
		check(i3.getType() == "ice");

		out("Ice copies xp and type in copy constructor");
		Ice i5 = Ice(i3);
		check(i5.getXP() == 10);
		check(i5.getType() == "ice");

		out("Ice copies xp in assignment operator");
		Ice i6 = Ice();
		check(i6.getXP() == 0);
		check(i6.getType() == "ice");
		
		i6 = i5;

		check(i6.getXP() == 10);
		check(i6.getType() == "ice");

		out("Cure | Constructor");
		Cure c1 = Cure();
		check(c1.getType() == "cure");
		check(c1.getXP() == 0);

		out("Cure | Copy constructor");
		Cure c2 = Cure(c1);
		check(c2.getType() == "cure");
		check(c2.getXP() == 0);

		out("Cure | Assignment operator");
		Cure c3 = Cure();
		check(c3.getType() == "cure");
		check(c3.getXP() == 0);

		c3 = c2;

		check(c3.getType() == "cure");
		check(c3.getXP() == 0);

		out("Cure | Destructor");
		{
			Cure c4 = Cure();
		}

		out("Cure | use modifies xp");
		c3.use(dummy);
		check(c3.getXP() == 10);
		check(c3.getType() == "cure");

		out("Cure copies xp and type in copy constructor");
		Cure c5 = Cure(c3);
		check(c5.getXP() == 10);
		check(c5.getType() == "cure");

		out("Cure copies xp in assignment operator");
		Cure c6 = Cure();
		check(c6.getXP() == 0);
		check(c6.getType() == "cure");
		
		c6 = c5;

		check(c6.getXP() == 10);
		check(c6.getType() == "cure");



		
	}
	
}