/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Crab.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 10:53:08 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/28 17:03:58 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CRAB_HPP
# define CRAB_HPP

# include "Victim.hpp"

class Crab : public Victim
{
private:
	Crab();

public:
	Crab(std::string name);
	Crab(const Crab &copy);
	Crab &operator= (const Crab &operand);
	virtual ~Crab();
	void getPolymorphed(void) const;
};

#endif