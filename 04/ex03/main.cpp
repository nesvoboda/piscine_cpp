/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 10:58:35 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/24 19:08:37 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

#include "Fire.hpp"

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
		// This example is quite important.
		// You may notice that the arguments to MateriaSource::learnMateria()
		// and Character::equip() are 
		// *always* allocated on the heap by the caller.

		// I assume that the given main must run without leaks,
		// therefore, I assume these arguments to be caller-allocated.
		// Failure to allocate them will lead to double-free and crash.
		// Also, I will free these pointers in my destructors, so don't reuse
		// any of these allocated objects.

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
		AMateria *i7 = i6.clone();
		check(i7->getType() == "ice");
		check(i7->getXP() == 10);
		delete i7;

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

		out("Cure | clone()");
		AMateria *c7 = c6.clone();
		check(c7->getType() == "cure");
		check(c7->getXP() == 10);
		delete c7;

		out("Fire | Constructor");
		Fire f1 = Fire();
		check(f1.getType() == "fire");
		check(f1.getXP() == 0);

		out("Fire | Copy constructor");
		Fire f2 = Fire(f1);
		check(f2.getType() == "fire");
		check(f2.getXP() == 0);

		out("Fire | Assignment operator");
		Fire f3 = Fire();
		check(f3.getType() == "fire");
		check(f3.getXP() == 0);

		f3 = f2;

		check(f3.getType() == "fire");
		check(f3.getXP() == 0);

		out("Fire | Destructor");
		{
			Fire f4 = Fire();
		}
		
		out("Fire | use modifies xp");
		eo("* shoots a fireball at Dummy *");
		f3.use(dummy);
		check(f3.getXP() == 10);
		check(f3.getType() == "fire");

		out("Fire copies xp and type in copy constructor");
		Fire f5 = Fire(f3);
		check(f5.getXP() == 10);
		check(f5.getType() == "fire");

		out("Fire copies xp in assignment operator");
		Fire f6 = Fire();
		check(f6.getXP() == 0);
		check(f6.getType() == "fire");
		
		f6 = f5;

		check(f6.getXP() == 10);
		check(f6.getType() == "fire");
		AMateria *f7 = f6.clone();
		check(f7->getType() == "fire");
		check(f7->getXP() == 10);
		delete f7;






		out("Character | Constructor");
		Character h1("bob");
		check(h1.getName() == "bob");
		
		out("Character | Copy constructor");
		Character h2(h1);
		check(h2.getName() == "bob");

		out("Character | Assignment operator");
		Character h3("pam");
		h3 = h2;
		check(h3.getName() == "bob");

		out("Character | Destructor");
		{
			Character h4("dwight");
		}

		out("Character | use() with empty slots");
		// Nothing should happen
		eo("");
		h3.use(-1, h1);
		h3.use(0, h1);
		h3.use(1, h1);
		h3.use(2, h1);
		h3.use(3, h1);
		h3.use(100, h1);

		ICharacter *target = new Character("Jim");
		AMateria *cure1 = new Cure();


		out("Character | equip() nullptr");
		h3.equip(nullptr);

		out("Character | equip() cure");
		h3.equip(cure1);
		eo("* heals Jim's wounds *");
		h3.use(0, *target);

		// This shouldn't do anything
		h3.use(1, *target);
		h3.use(-1, *target);

		out("Character | equip() ice");
		AMateria *ice1 = new Ice();
		h3.equip(ice1);
		eo("* shoots an ice bolt at Jim *");
		h3.use(1, *target);



		out("Character | unequip()");
	
		h3.unequip(0);
		eo("");
	
		h3.use(0, *target);
	
		out("Character | unequip() nonexisting item");
		h3.unequip(-1);
		h3.unequip(2);
		h3.unequip(100);
	
		out("Character | assignment with items");
		Character h5 = Character("Erin");
		AMateria *ice2 = new Ice();
		AMateria *cure2 = new Ice();
		h5.equip(ice2);
		h5.equip(cure2);
	
		Character h6 = Character("Sammy");
		h6 = h5;
		check(h6.getName() == "Erin");
		eo("* shoots an ice bolt at Jim *");
		h6.use(0, *target);

	

		out("Character | copy construction with items");
		Character h7 = Character(h6);
		eo("* shoots an ice bolt at Jim *");
		h6.use(0, *target);

		out("Character | assignment with items on the left");
		h6 = h5;
		eo("* shoots an ice bolt at Jim *");
		h6.use(0, *target);
		
		out("Character | trying to equip too many items");
		Character h8 = Character("Michael");
		h8.equip(new Ice());
		h8.equip(new Ice());
		h8.equip(new Ice());
		h8.equip(new Ice());
		h8.equip(ice1);
		h8.equip(ice1);



		out("Character | equality operator with empty item slots");
		Character h9 = Character("Oscar");
		h9.equip(new Ice());
		AMateria *unequip_later = new Cure();
		h9.equip(unequip_later);
		h9.equip(new Ice());
		h9.unequip(1);
		delete unequip_later;

		Character h10 = Character("Stanley");
		h10 = h9;

		out("MateriaSource | Constructor");

		MateriaSource m1 = MateriaSource();
		// nothing should happen
		m1.learnMateria(nullptr);

		// nothing should happen
		m1.createMateria("nothing");

		out("MateriaSource | Copy Constructor");
		MateriaSource m2 = MateriaSource(m1);

		// nothing should happen
		m2.learnMateria(nullptr);
	
		// nothing should happen
		m2.createMateria("nothing");

		out("MateriaSource | Assignment operator");

		MateriaSource m3 = MateriaSource();

		m3 = m2;

		// nothing should happen
		m3.learnMateria(nullptr);

		// nothing should happen
		m3.createMateria("nothing");

		out("MateriaSource | Destructor");
		{
			MateriaSource m4;
		}

		// This way cure has different XP than Ice;
		cure1->use(dummy);

		out("MateriaSource | learnMateria -> ice");
		AMateria *ice3 = new Ice();
		m2.learnMateria(ice3);
		AMateria *newIce;
		newIce = m2.createMateria("ice");
		check(newIce->getType() == "ice");
		check(newIce->getXP() == ice3->getXP());

		out("MateriaSource | learnMateria -> cure");
		AMateria *cure3 = new Cure();
		m2.learnMateria(cure3);
		AMateria *newCure;
		newCure = m2.createMateria("cure");
		check(newCure->getType() == "cure");
		check(newCure->getXP() == cure3->getXP());
	
		// This shouldn't do anything
		m2.createMateria("Whatever");
		

		out("MateriaSource | Copy construction with objects");
		MateriaSource m5 = MateriaSource(m2);


		out("MateriaSource | Assignment operator with objects");
		MateriaSource m6 = MateriaSource();
		m6 = m5;
		out("MateriaSource | Assignment operator with objects");

		out("MateriaSource | Assignment operator with old objects");
		MateriaSource m7 = MateriaSource();
		m7.learnMateria(new Ice());
		m7.learnMateria(new Cure());
		m7 = m6;

	

		out("MateriaSource | Inventory full");
		MateriaSource m8 = MateriaSource();
		m8.learnMateria(new Ice());
		m8.learnMateria(new Cure());
		m8.learnMateria(new Ice());
		m8.learnMateria(new Cure());
		AMateria *deadCure = new Cure();
		m8.learnMateria(deadCure);
		delete deadCure;

		out("MateriaSource | Inventory full and unknown type");
		m8.createMateria("Whatever");

		delete target;
		delete newCure;
		delete newIce;
		delete cure1;
	}

	// Uncomment the 2 following lines if you're using leaks on Mac OS instead of Valgrind
	// std::cout << "You now have 30 seconds to check for leaks" << std::endl;
	// sleep(30);
	return 0;	
}