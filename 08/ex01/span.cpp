/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 21:12:49 by ashishae          #+#    #+#             */
/*   Updated: 2020/10/11 21:49:20 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <iostream>

Span::Span(unsigned int N)
{
	this->storage = std::vector<int>();
	this->storage.reserve(5);
	this->n = N;
	// std::cout << this->storage.size() << std::endl;
}

Span::~Span()
{
	this->n = 0;
}

Span::Span(const Span &copy)
{
	this->storage = copy.storage;
	this->n = copy.n;
}

Span &Span::operator= (const Span &operand)
{
	this->storage = operand.storage;
	this->n = operand.n;
	return (*this);
}

void Span::addNumber(int n)
{
	if (this->storage.size() < this->n)
	{
		this->storage.push_back(n);
		std::sort(this->storage.begin(), this->storage.end());
	}
	else
		throw Span::SpanFull();
}

int Span::shortestSpan(void)
{
	if (this->storage.size() < 2)
		throw Span::NotEnoughNumbers();
	int minRange = this->longestSpan();
	for (std::vector<int>::iterator i = storage.begin(); i < storage.end()-1; i++)
	{
		if ((*(i+1) - *i) < minRange)
		{
			minRange = (*(i+1) - *i);
		}
	}
	return minRange;
	
}

int Span::longestSpan(void)
{
	if (this->storage.size() < 2)
		throw Span::NotEnoughNumbers();
	return (*(this->storage.end()-1) - *(this->storage.begin()));
}

const char* Span::NotEnoughNumbers::what() const throw()
{
	return "There isn't enough numbers in this Span to calculate spans";
}

const char* Span::SpanFull::what() const throw()
{
	return "This Span is full, you can't add any more numbers to it";
}