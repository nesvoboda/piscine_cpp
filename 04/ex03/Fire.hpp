/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 10:58:35 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/23 13:29:18 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIRE_HPP
# define FIRE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Fire : public AMateria
{
public:
	Fire();
	Fire(const Fire &copy);
	Fire &operator= (const Fire &operand);
	~Fire();
	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif