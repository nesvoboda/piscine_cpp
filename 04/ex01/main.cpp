/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 13:48:33 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/13 18:58:54 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Enemy.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"

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
	// Subject tests
	{
		Character* me = new Character("me");
		std::cout << *me;
		Enemy* b = new RadScorpion();
		AWeapon* pr = new PlasmaRifle();
		AWeapon* pf = new PowerFist();
		me->equip(pr);
		std::cout << *me;
		me->equip(pf);
		me->attack(b);
		std::cout << *me;
		me->equip(pr);
		std::cout << *me;
		me->attack(b);
		std::cout << *me;
		me->attack(b);
		std::cout << *me;
	}

	// PlasmaRifle
	out("Plasma | Constructor");
	PlasmaRifle pr;
	check(pr.getDamage() == 21);
	check(pr.getAPCost() == 5);
	
	out("Plasma | Copy constructor");
	PlasmaRifle pr2 = pr;

	check(pr2.getDamage() == 21);
	check(pr2.getAPCost() == 5);

	out("Plasma | Assignment operator");
	PlasmaRifle pr3;

	pr3 = pr2;
	check(pr3.getDamage() == 21);
	check(pr3.getAPCost() == 5);

	out("Plasma | Destructor");
	{
		PlasmaRifle pr4;
	}

	out("Plasma | attack()");
	eo("* piouuu piouuu piouuu *");
	pr3.attack();

	// PowerFist
	out("PowerFist | Constructor");
	PowerFist pf;
	check(pf.getDamage() == 50);
	check(pf.getAPCost() == 8);
	
	out("PowerFist | Copy constructor");
	PowerFist pf2 = pf;

	check(pf2.getDamage() == 50);
	check(pf2.getAPCost() == 8);

	out("PowerFist | Assignment operator");
	PowerFist pf3;

	pf3 = pf2;
	check(pf3.getDamage() == 50);
	check(pf3.getAPCost() == 8);

	out("PowerFist | Destructor");
	{
		PowerFist pf4;
	}

	out("PowerFist | attack()");
	eo("* pschhh... SBAM! *");
	pf3.attack();

	// SuperMutant
	out("SuperMutant | Constructor");
	SuperMutant sm;
	eo("Gaaah. Me want smash heads!");
	check(sm.getHP() == 170);
	check(sm.getType() == "Super Mutant");
	
	out("SuperMutant | Copy constructor");
	eo("Gaaah. Me want smash heads!");
	SuperMutant sm2 = sm;

	check(sm2.getHP() == 170);
	check(sm2.getType() == "Super Mutant");

	out("SuperMutant | Assignment operator");
	eo("Gaaah. Me want smash heads!");
	SuperMutant sm3;

	pf3 = pf2;
	check(sm3.getHP() == 170);
	check(sm3.getType() == "Super Mutant");

	out("SuperMutant | Destructor");
	{
		eo("Gaaah. Me want smash heads!");
		SuperMutant sm4;
		eo("Aaargh...");
	}

	out("SuperMutant | takeDamage()");
	int buffer = sm3.getHP();
	sm3.takeDamage(10);
	std::cout << sm3.getHP() << std::endl;
	check(sm3.getHP() == (buffer - 7));

	return 0;
}