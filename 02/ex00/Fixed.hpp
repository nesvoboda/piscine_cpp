/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 11:34:32 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/30 11:45:01 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed &copy);
	Fixed &operator= (const Fixed &operand);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);

private:
	int value;
	static const int fbits;
};


#endif
