/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 15:05:13 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/13 18:13:13 by ashishae         ###   ########.fr       */
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

public:
	Victim(std::string name);
	Victim(const Victim &copy);
	Victim &operator= (const Victim &operand);
	~Victim();
	std::string getName(void) const;
	void getPolymorphed(void) const;

private:
	std::string name;
};

std::ostream& operator<<(std::ostream& os, const Victim& vic);

#endif
