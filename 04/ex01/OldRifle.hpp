/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OldRifle.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 13:33:45 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/28 17:09:43 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OLD_RIFLE_HPP
# define OLD_RIFLE_HPP

# include "AWeapon.hpp"

class OldRifle : public AWeapon
{
public:
	OldRifle();
	OldRifle(const OldRifle &copy);
	OldRifle &operator= (const OldRifle &operand);
	virtual ~OldRifle();
	void attack() const;

};

#endif