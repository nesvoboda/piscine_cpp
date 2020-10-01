/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NasalDemon.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 13:33:33 by ashishae          #+#    #+#             */
/*   Updated: 2020/10/01 15:25:41 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NASAL_DEMON_HPP
# define NASAL_DEMON_HPP

# include "Enemy.hpp"

// http://www.catb.org/jargon/html/N/nasal-demons.html

class NasalDemon : public Enemy
{
public:
	NasalDemon();
	NasalDemon(const NasalDemon &copy);
	NasalDemon &operator= (const NasalDemon &operand);
	virtual ~NasalDemon();
};

#endif