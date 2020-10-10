/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:52:24 by ashishae          #+#    #+#             */
/*   Updated: 2020/10/09 19:32:54 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template <typename T>
class Array {

public:
	Array();
	Array(unsigned int n);
	~Array();
	Array(const Array &copy);
	Array &operator= (const Array &operand);
	
	T& operator[](unsigned int idx);
	const T& operator[](unsigned int idx) const;
	
	unsigned int size(void) const;
	class OutOfBoundsException: public std::exception {
		public:
			virtual const char* what() const throw();
	};

private:
	T *storage;
	unsigned int _size;
};

template <typename T>
Array<T>::Array()
{
	this->_size = 0;
	this->storage = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->_size = n;
	this->storage = new T[n];
	for (unsigned int i = 0; i < n; i++)
	{
		// This initializes every cell to type's default value;
		this->storage[i] = T();
	}
}

template <typename T>
Array<T>::~Array()
{
	delete [] this->storage;
	this->storage = nullptr;
	// This will protect the memory from being accessed after it is deallocated
	this->_size = 0;
}

template <typename T>
Array<T>::Array(const Array<T> &copy)
{
	this->_size = copy.size();
	this->storage = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
	{
		this->storage[i] = copy[i];
	}
}

template <typename T>
Array<T> &Array<T>::operator= (const Array<T> &operand)
{
	if (this != &operand)
	{
		// We only need to reallocate if the sizes don't match
		if (this->_size != operand.size())
		{
			delete [] this->storage;
			this->_size = operand.size();
			this->storage = new T[this->_size];
		}
		for (unsigned int i = 0; i < this->_size; i++)
		{
			this->storage[i] = operand[i];
		}
	}
	return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int idx)
{
	if (this->_size == 0 ||  idx > (this->_size - 1))
		throw Array::OutOfBoundsException();
	else
		return this->storage[idx];
}

template <typename T>
const T& Array<T>::operator[](unsigned int idx) const
{
	if (this->_size == 0 || idx > (this->_size - 1))
		throw Array::OutOfBoundsException();
	else
		return this->storage[idx];
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
	return "The element is out of bounds of the array";
}

template <typename T>
unsigned int Array<T>::size() const
{
	return this->_size;
}

#endif