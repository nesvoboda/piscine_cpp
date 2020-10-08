/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 12:07:34 by ashishae          #+#    #+#             */
/*   Updated: 2020/10/08 14:53:54 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <exception>

void identify_from_pointer(Base *p)
{
	A *to_a = dynamic_cast<A*>(p);
	B *to_b = dynamic_cast<B*>(p);
	C *to_c = dynamic_cast<C*>(p);
	if (to_a != nullptr)
		std::cout << "A" << std::endl;
	if (to_b != nullptr)
		std::cout << "B" << std::endl;
	if (to_c != nullptr)
		std::cout << "C" << std::endl;
}

void identify_from_reference(Base &r)
{
	int a = 1;
	int b = 1;
	int c = 1;

	try
	{
		(void)dynamic_cast<A&>(r);
	}
	catch(const std::bad_cast& e)
	{
		a = 0;
	}
	
	try
	{
		(void)dynamic_cast<B&>(r);
	}
	catch(const std::bad_cast& e)
	{
		b = 0;
	}
	
	try
	{
		(void)dynamic_cast<C&>(r);
	}
	catch(const std::bad_cast& e)
	{
		c = 0;
	}

	if (a != 0)
		std::cout << "A" << std::endl;
	if (b != 0)
		std::cout << "B" << std::endl;
	if (c != 0)
		std::cout << "C" << std::endl;
}

int main(void)
{
	srand (time(NULL));
	Base b = Base();
	
	Base *first = b.generate();
	

	std::cout << std::endl << "Guessing class from pointer" << std::endl;
	identify_from_pointer(first);
	std::cout << std::endl << "Guessing class from reference" << std::endl;
	identify_from_reference(*first);
}