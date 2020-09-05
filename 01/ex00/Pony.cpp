/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 19:28:11 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/04 17:48:15 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(void)
{
	std::cout << "Pony constructor called\n";
}

void	Pony::neigh(void)
{
	std::cout << "Neeeeeigh\n";
	this->neighCounter += 1;
}

Pony::~Pony(void)
{
	std::cout << "Pony destructor called\n";
}
