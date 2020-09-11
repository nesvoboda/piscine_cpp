/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 18:44:07 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/05 12:25:34 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TACTICAL_MARINE_HPP
# define TACTICAL_MARINE_HPP

# include "ISpaceMarine.hpp"
# include <iostream>

class TacticalMarine : public ISpaceMarine
{
public:
	TacticalMarine();
	TacticalMarine(const TacticalMarine &copy);
	TacticalMarine &operator= (const TacticalMarine &operand);
	~TacticalMarine();

	ISpaceMarine* clone() const;
	void battleCry() const;
	void rangedAttack() const;
	void meleeAttack() const;
};

#endif