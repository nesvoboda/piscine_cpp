/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 14:11:55 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/26 15:35:58 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include <string>
# include "Zombie.hpp"
# include <cstdlib>

class ZombieEvent
{

public:
	ZombieEvent();
	void setZombieType(std::string type);
	void randomChump(void);
	Zombie *newZombie(std::string name);


private:
	std::string zombieType;

};

#endif