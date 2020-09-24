/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 10:58:35 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/24 14:31:16 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *localMateria[4];

public:
	MateriaSource();
	MateriaSource(const MateriaSource &copy);
	MateriaSource &operator= (const MateriaSource &operand);
	~MateriaSource();
	// The argument to learnMateria is assumed to be heap-allocated.
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
};

#endif