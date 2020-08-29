/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:21:00 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/27 17:52:09 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <sstream>

Brain::Brain(void)
{
	/* initialize random seed: */
 	srand (time(NULL));

	this->volume = rand() % 1000;
	this->iq = rand() % 150;
}

std::string Brain::identify()
{
	std::stringstream sst;

	sst << this;

	return sst.str();
}
