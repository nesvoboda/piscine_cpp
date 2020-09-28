/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 13:48:33 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/28 17:52:01 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Enemy.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "OldRifle.hpp"
#include "NasalDemon.hpp"

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
		// Subject tests
		std::cout << "\n Subject tests \n" << std::endl;
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

			// This is necessary to pass Valgrind's leaks check.
			delete me;
			delete pr;
			delete pf;
		}

		std::cout << "\n Additional tests \n" << std::endl;

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

		// OldRifle
		out("OldRifle | Constructor");
		OldRifle orf;
		check(orf.getDamage() == 50);
		check(orf.getAPCost() == 8);
		
		out("OldRifle | Copy constructor");
		OldRifle orf2 = orf;

		check(orf2.getDamage() == 50);
		check(orf2.getAPCost() == 8);

		out("OldRifle | Assignment operator");
		OldRifle orf3;

		orf3 = orf2;
		check(orf3.getDamage() == 50);
		check(orf3.getAPCost() == 8);

		out("OldRifle | Destructor");
		{
			OldRifle orf4;
		}

		out("OldRifle | attack()");
		eo("* BANG! *");
		orf3.attack();

		// SuperMutant
		out("SuperMutant | Constructor");
		eo("Gaaah. Me want smash heads!");
		SuperMutant sm;
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

		sm3 = sm2;
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
		check(sm3.getHP() == (buffer - 7));

		out("SuperMutant | takeDamage() with negative damage");
		buffer = sm3.getHP();
		sm3.takeDamage(-10);
		check(sm3.getHP() == buffer);

		// RadScorpion
		out("RadScorpion | Constructor");
		eo("* click click click *");
		RadScorpion rs;
		check(rs.getHP() == 80);
		check(rs.getType() == "RadScorpion");
		
		out("RadScorpion | Copy constructor");
		eo("* click click click *");
		RadScorpion rs2 = rs;

		check(rs2.getHP() == 80);
		check(rs2.getType() == "RadScorpion");

		out("RadScorpion | Assignment operator");
		eo("* click click click *");
		RadScorpion rs3;

		rs3 = rs2;
		check(rs3.getHP() == 80);
		check(rs3.getType() == "RadScorpion");

		out("RadScorpion | Destructor");
		{
			eo("* click click click *");
			RadScorpion rs4;
			eo("* SPROTCH *");
		}

		out("RadScorpion | takeDamage()");
		buffer = rs3.getHP();
		rs3.takeDamage(10);
		check(rs3.getHP() == (buffer - 10));

		out("RadScorpion | takeDamage() with negative damage");
		buffer = rs3.getHP();
		rs3.takeDamage(-10);
		check(rs3.getHP() == buffer);

		// NasalDemon
		out("NasalDemon | Constructor");
		eo("* cd;/bin/rm -rf *");
		NasalDemon nd;
		check(nd.getHP() == 42);
		check(nd.getType() == "Nasal Demon");
		
		out("NasalDemon | Copy constructor");
		eo("* cd;/bin/rm -rf *");
		NasalDemon nd2 = nd;

		check(nd2.getHP() == 42);
		check(nd2.getType() == "Nasal Demon");

		out("NasalDemon | Assignment operator");
		eo("* cd;/bin/rm -rf *");
		NasalDemon nd3;

		nd3 = nd2;
		check(nd3.getHP() == 42);
		check(nd3.getType() == "Nasal Demon");

		out("NasalDemon | Destructor");
		{
			eo("* cd;/bin/rm -rf *");
			NasalDemon nd4;
			eo("* UNDEFINED BEHAVIOUR *");
		}

		out("NasalDemon | takeDamage()");
		buffer = nd3.getHP();
		nd3.takeDamage(10);
		check(nd3.getHP() == (buffer - 10));

		out("NasalDemon | takeDamage() with negative damage");
		buffer = nd3.getHP();
		nd3.takeDamage(-10);
		check(nd3.getHP() == buffer);

		// Character
		out("Character | Constructor");
		Character jim("Jim");
		check(jim.getAP() == 40);
		check(jim.getName() == "Jim");
		
		out("Character | Copy constructor");
		Character jimothy = jim;
		check(jimothy.getAP() == 40);
		check(jimothy.getName() == "Jim");


		out("Character | Assignment operator");
		Character dwight("Dwight");
		check(dwight.getAP() == 40);
		check(dwight.getName() == "Dwight");

		dwight = jim;
		check(dwight.getAP() == 40);
		check(dwight.getName() == "Jim");

		out("Character | Destructor");
		{
			Character ryan("Ryan");
		}

		out("Character | recoverAP() with a max value");
		dwight.recoverAP();
		check(dwight.getAP() == 40);

		out("Character | << overload");
		eo("Jim has 40 AP and is unarmed");
		std::cout << dwight << std::endl;

		out("Character | hasWeapon()");
		check(dwight.hasWeapon() == 0);
		check(dwight.getWeaponName() == "");

		out("Character | attack() without a weapon");
		eo("Get yourself a weapon first");
		dwight.attack(&sm);
		dwight.recoverAP();


		out("Character | equip()");
		dwight.equip(&pr3);

		eo("Jim has 40 AP and wields a Plasma Rifle");
		std::cout << dwight << std::endl;

		check(dwight.getWeaponName() == "Plasma Rifle");
		check(dwight.hasWeapon() == 1);
		

		out("Character | attack()");
		buffer = sm.getHP();

		eo("Jim attacks Super Mutant with a Plasma Rifle\n* piouuu piouuu piouuu *");
		dwight.attack(&sm);
		check(sm.getHP() == (buffer - pr3.getDamage() + 3));
		check(dwight.getAP() == 40 - pr3.getAPCost());

		out("Character | recoverAP()");
		dwight.equip(&pf);
		eo("Jim attacks Super Mutant with a Power Fist\n* pschhh... *");
		dwight.attack(&sm);
		
		
		buffer = dwight.getAP();
		dwight.recoverAP();
		check(dwight.getAP() == buffer + 10);

		out("Character | attack() deletes target");
		// dwight.equip(&pf);

		RadScorpion *target = new RadScorpion();

		eo("Jim attacks RadScorpion with a Power Fist\n* pschhh... SBAM! *");
		dwight.attack(target);

		eo("Jim attacks RadScorpion with a Power Fist\n* pschhh... SBAM! *\n* SPROTCH *");
		dwight.attack(target);

		out("Character | attack() with insufficient AP");

		eo("Jim attacks SuperMutant with a Power Fist\n* pschhh... SBAM! *");
		dwight.attack(&sm);

		eo("Jim attacks SuperMutant with a Power Fist\n* pschhh... SBAM! *");
		dwight.attack(&sm);

		eo("AP too low :(");
		dwight.attack(&sm);

		out("Character | recoverAP() to a maximum");
		Character michael("Michael");
		michael.equip(&pf);
		check(michael.getAP() == 40);
		eo("Michael attacks RadScorpion with a Power Fist\n* pschhh... SBAM! *");
		michael.attack(&rs2);
		michael.recoverAP();
		check(michael.getAP() == 40);
		
		std::cout << "\n Additional tests end\n" << std::endl;
	}

	// Uncomment the 2 following lines if you're using leaks on Mac OS instead of Valgrind
	// std::cout << "You now have 30 seconds to check for leaks" << std::endl;
	// sleep(30);

	return 0;
}