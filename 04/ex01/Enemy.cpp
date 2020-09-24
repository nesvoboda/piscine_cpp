/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 13:48:33 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/16 19:25:30 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(int new_hp, std::string const &new_type) :
	hp(new_hp), type(new_type)
{
}

Enemy::Enemy(const Enemy &copy) :
	hp(copy.hp), type(copy.type)
{
}

Enemy::~Enemy()
{
}


std::string const &Enemy::getType() const
{
	return this->type;
}

Enemy &Enemy::operator=(const Enemy &operand)
{
	this->hp = operand.hp;
	this->type = operand.type;
	return (*this);
}

void Enemy::takeDamage(int damage)
{
	if (damage < 0)
		return;
	this->loseHP(damage);
}

void Enemy::loseHP(int damage)
{
	if (damage < 0)
		return;
	if (this->hp <= damage)
		this->hp = 0;
	else
		this->hp -= damage;
}

int Enemy::getHP() const
{
	return this->hp;
}