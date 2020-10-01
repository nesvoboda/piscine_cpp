/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NasalDemon.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 13:33:29 by ashishae          #+#    #+#             */
/*   Updated: 2020/10/01 15:25:38 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NasalDemon.hpp"

NasalDemon::NasalDemon() : Enemy(42, "Nasal Demon")
{
	std::cout << "* cd;/bin/rm -rf *" << std::endl;
}

NasalDemon::NasalDemon(const NasalDemon &copy) : Enemy(copy)
{
	std::cout << "* cd;/bin/rm -rf *" << std::endl;
}

NasalDemon & NasalDemon::operator= (const NasalDemon &operand)
{
	Enemy::operator=(operand);
	return (*this);
}

NasalDemon::~NasalDemon()
{
	std::cout << "* UNDEFINED BEHAVIOUR *" << std::endl;
}