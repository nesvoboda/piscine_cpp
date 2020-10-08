/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 21:44:38 by ashishae          #+#    #+#             */
/*   Updated: 2020/10/08 12:58:41 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "time.h"
Base::~Base()
{
}

Base * Base::generate(void)
{
	int pick = rand() % 3;

	if (pick == 0)
	{
		return new A();
	}
	else if (pick == 1)
	{
		return new B();
	}
	else
	{
		return new C();
	}
}