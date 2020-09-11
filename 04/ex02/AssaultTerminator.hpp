/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 18:51:51 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/05 12:31:04 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ASSAULT_TERMINATOR_HPP
# define ASSAULT_TERMINATOR_HPP

# include "ISpaceMarine.hpp"
# include <iostream>

class AssaultTerminator : public ISpaceMarine
{
public:
	AssaultTerminator();
	AssaultTerminator(const AssaultTerminator &copy);
	AssaultTerminator &operator= (const AssaultTerminator &operand);
	~AssaultTerminator();

	ISpaceMarine* clone() const;
	void battleCry() const;
	void rangedAttack() const;
	void meleeAttack() const;
};

#endif