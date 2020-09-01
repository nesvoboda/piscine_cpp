/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 13:48:33 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/01 17:50:11 by ashishae         ###   ########.fr       */
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

public:
	Enemy();
	Enemy(int hp, std::string const & type);
	Enemy(const Enemy &copy);
	Enemy &operator= (const Enemy &operand);
	virtual ~Enemy();
	std::string /* something */ getType() const;
	virtual void takeDamage(int);
	void loseHP(int);
	int getHP() const;

};

#endif