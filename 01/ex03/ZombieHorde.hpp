/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 15:35:08 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/26 16:29:29 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

# include "Zombie.hpp"
# include <cstdlib>

class ZombieHorde
{
public:
	ZombieHorde(int N);
	~ZombieHorde(void);
	void announce(void);

private:
	int N;
	Zombie *storage;
};


#endif