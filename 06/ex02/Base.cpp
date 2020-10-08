/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 21:44:38 by ashishae          #+#    #+#             */
/*   Updated: 2020/10/08 15:07:29 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "time.h"

// Output can be turned off by compiling without DEBUG
#ifdef DEBUG
# define PRINT 1
#else
# define PRINT 0
#endif

#include <iostream>

Base::~Base()
{
}

Base * Base::generate(void)
{
	int pick = rand() % 3;
	
	if (pick == 0)
	{
		if (PRINT)
			std::cout << "generate() created instance of class A" << std::endl;
		return new A();
	}
	else if (pick == 1)
	{
		if (PRINT)
			std::cout << "generate() created instance of class B" << std::endl;
		return new B();
	}
	else
	{
		if (PRINT)
			std::cout << "generate() created instance of class C" << std::endl;
		return new C();
	}
}