/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 11:34:32 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/30 12:35:36 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

# include <cmath>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed &copy);
	Fixed(const int integer);
	Fixed(const float floating_point);
	Fixed &operator= (const Fixed &operand);
	// Fixed &operator<< (const Fixed &operand);
	~Fixed();
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

private:
	int value;
	static const int fbits;
};

std::ostream& operator<< (std::ostream& os, const Fixed &operand);

#endif
