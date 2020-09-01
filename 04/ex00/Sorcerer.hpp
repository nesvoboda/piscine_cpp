/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 15:05:13 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/01 13:35:01 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <iostream>
# include <string>
# include "Victim.hpp"
# include "Peon.hpp"

class Sorcerer
{
public:
	Sorcerer();
	Sorcerer(std::string name, std::string title);
	Sorcerer(const Sorcerer &copy);
	Sorcerer &operator= (const Sorcerer &operand);
	~Sorcerer();
	std::string getName(void) const;
	std::string getTitle(void) const;
	void polymorph(Victim const &) const;
	void polymorph(Peon const &po) const;

private:
	std::string name;
	std::string title;

};

std::ostream& operator<<(std::ostream& os, const Sorcerer& sorc);

#endif