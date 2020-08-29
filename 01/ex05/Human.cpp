/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:21:00 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/27 17:52:02 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

std::string Human::identify(void)
{
	return this->brain.identify();
}

const Brain &Human::getBrain(void)
{
	return this->brain;
}
