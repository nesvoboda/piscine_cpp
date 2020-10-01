/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 15:05:13 by ashishae          #+#    #+#             */
/*   Updated: 2020/10/01 15:34:36 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <iostream>
# include <string>
# include "Victim.hpp"
# include "Peon.hpp"
# include "Crab.hpp"

class Sorcerer
{
private:
	// The class can’t be instanciated without parameters 
	Sorcerer();
	std::string name;
	std::string title;

public:
	Sorcerer(std::string name, std::string title);
	Sorcerer(const Sorcerer &copy);
	Sorcerer &operator= (const Sorcerer &operand);
	~Sorcerer();
	std::string getName(void) const;
	std::string getTitle(void) const;
	void polymorph(Victim const &) const;

};

std::ostream& operator<<(std::ostream& os, const Sorcerer& sorc);

#endif
