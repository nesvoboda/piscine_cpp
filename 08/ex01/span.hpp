/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 21:06:21 by ashishae          #+#    #+#             */
/*   Updated: 2020/10/20 12:03:30 by ashishae         ###   ########.fr       */
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

	template <typename T>
	void addRange(T start, T end)
	{
		int volumeLeft = this->n - this->storage.size();
		if (volumeLeft < std::distance(start, end))
			throw Span::SpanFull();
		// No more calls to addNumber or pushBack! Algorithm magic
		this->storage.insert(this->storage.end(), start, end);
		// In C++11 you can avoid unnecessary sorting by is_sorted
		std::sort(this->storage.begin(), this->storage.end());
	}

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