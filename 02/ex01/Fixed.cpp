/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 11:34:20 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/06 08:28:45 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fbits = 8;

Fixed::Fixed() :
	value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = integer << this->fbits;
}

Fixed::Fixed(const float floating_point)
{
	std::cout << "Float constructor called" << std::endl;
	float x;

	x = floating_point;
	x *= (1 << this->fbits);

	this->value = roundf(x);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) :
	value(copy.value)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator= (const Fixed &operand)
{
	std::cout << "Assignation operator called" << std::endl;
	value = operand.value;
	return *this;
}

std::ostream &operator<< (std::ostream &os, const Fixed &operand)
{
	os << operand.toFloat();
	return os;
}


int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

float Fixed::toFloat(void) const
{
	float x;
	x = this->value;

	x /= float(1 << this->fbits);
	return x;
}

int Fixed::toInt(void) const
{
	return this->value >> this->fbits;
}