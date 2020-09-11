/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 18:44:07 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/05 11:54:36 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP

# include "ISquad.hpp"

class Squad : public ISquad
{
public:
	Squad();
	Squad(const Squad &copy);
	Squad &operator= (const Squad &operand);
	~Squad();

	int getCount() const;
	ISpaceMarine* getUnit(int) const;
	int push(ISpaceMarine *);

private:
	ISpaceMarine **storage;
	int count;
};

#endif