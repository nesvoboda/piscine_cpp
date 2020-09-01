/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 15:05:13 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/01 13:27:29 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

# include "Victim.hpp"

class Peon : public Victim
{
public:
	Peon();
	Peon(std::string name);
	Peon(const Peon &copy);
	Peon &operator= (const Peon &operand);
	~Peon();
	void getPolymorphed(void) const;
};

#endif