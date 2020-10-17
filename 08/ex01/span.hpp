/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 21:06:21 by ashishae          #+#    #+#             */
/*   Updated: 2020/10/11 21:59:57 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <exception>
# include <algorithm>

class Span {

public:
	Span(unsigned int N);
	~Span();
	Span(const Span &copy);
	Span &operator= (const Span &operand);

	void addNumber(int n);
	int shortestSpan(void);
	int longestSpan(void);

	class NotEnoughNumbers: public std::exception
	{
		public:
		virtual const char* what() const throw();
	};
	class SpanFull: public std::exception
	{
		public:
		virtual const char* what() const throw();
	};

private:
	Span();
	std::vector<int> storage;
	unsigned int n;
	
};

#endif