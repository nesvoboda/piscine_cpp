/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 15:05:13 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/01 13:12:58 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>
# include <string>

class Victim
{
public:
	Victim();
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