/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 15:05:13 by ashishae          #+#    #+#             */
/*   Updated: 2020/10/01 15:33:48 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>
# include <string>

class Victim
{
private:
	// A victim without a name doesn't make a lot of sense
	Victim();
	std::string name;

public:
	Victim(std::string name);
	Victim(const Victim &copy);
	Victim &operator= (const Victim &operand);
	virtual ~Victim();
	std::string getName(void) const;
	virtual void getPolymorphed(void) const;
};

std::ostream& operator<<(std::ostream& os, const Victim& vic);

#endif
