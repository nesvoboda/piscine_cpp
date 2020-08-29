/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 14:11:55 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/27 15:53:25 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie
{

public:

	Zombie(std::string name, std::string type);
	Zombie(void);
	void	announce(void);
	void	setName(std::string name);
	void	setType(std::string name);
	std::string name;

private:

	
	std::string type;

};

#endif