/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 13:48:33 by ashishae          #+#    #+#             */
/*   Updated: 2020/10/01 15:25:16 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <string>
# include <iostream>

class Enemy
{
private:
	int hp;
	std::string type;
	Enemy();

public:
	Enemy(int hp, std::string const & type);
	Enemy(const Enemy &copy);
	Enemy &operator= (const Enemy &operand);
	virtual ~Enemy();
	std::string const &getType() const;
	virtual void takeDamage(int);
	int getHP() const;

};

#endif