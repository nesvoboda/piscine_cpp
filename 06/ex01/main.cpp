/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 10:35:14 by ashishae          #+#    #+#             */
/*   Updated: 2020/10/10 15:52:39 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <stdexcept>

#include <stdlib.h>

#include "main.hpp"

// Global variables to test
std::string	s1_control;
int			n_control;
std::string	s2_control;


// Our data is of fixed length, so we know how
// to structure our serialization format

// Bytes 0-7: s1 (8 bytes)
// Bytes 8-11: n (4 bytes)
// Bytes 12-19: s2 (8 bytes)

// Total: 8+4+8 = 20 bytes

void encode_string(std::string s, unsigned char *pos)
{
	if (s.length() > 9)
		throw std::exception();
	int stop = s.length();
	for (int i = 0; i < 8; i++)
	{
		if (i < stop)
			pos[i] = static_cast<unsigned char>(s[i]);
		else
			pos[i] = static_cast<unsigned char>(0);
	}
}

std::string decode_string(unsigned char *pos)
{
	std::string temp;
	for (int i = 0; i < 8; i++)
	{
		if (pos[i] != 0)
		{
			temp += static_cast<char>(pos[i]);
		}
	}
	return temp;
}

void encode_int(int i, unsigned char *pos)
{
	pos[0] = static_cast<unsigned char>(i & 0x000000ff);
	pos[1] = static_cast<unsigned char>((i & 0x0000ff00) >> 8);
	pos[2] = static_cast<unsigned char>((i & 0x00ff0000) >> 16);
	pos[3] = static_cast<unsigned char>((i & 0xff000000 ) >> 24);
}

int decode_int(unsigned char *pos)
{
	int i = 0;

	i += static_cast<int>(pos[0]);
	i += static_cast<int>(pos[1]) << 8;
	i += static_cast<int>(pos[2]) << 16;
	i += static_cast<int>(pos[3]) << 24;
	return i;
}

std::string create_string()
{
	// 9th byte is for '\0'
	char buf[9];
	int temp;
	for (int i = 0; i < 8; i++)
	{
		while (!isalnum(temp = rand() % 123))
		{
			temp = rand() % 123;
		}
		buf[i] = static_cast<char>(temp);
	}
	buf[8] = static_cast<char>(0);
	return (std::string(buf));
}

void *serialize(void)
{
	Data d;

	d.s1 = create_string();
	d.s2 = create_string();
	d.n = rand();

	s1_control = d.s1;
	n_control = d.n;
	s2_control = d.s2;

	unsigned char *ret = new unsigned char[20];

	encode_string(d.s1, &ret[0]);
	encode_int(d.n, &ret[8]);
	encode_string(d.s2, &ret[12]);
	return reinterpret_cast<void *>(ret);
}

Data * deserialize(void * raw)
{
	unsigned char *val = reinterpret_cast<unsigned char *>(raw);

	Data *d = new Data;
	d->s1 = decode_string(val);
	d->n = decode_int(&val[8]);
	d->s2 = decode_string(&val[12]);
	return d;
}

int main(void)
{
	srand (time(NULL));

	void *s = serialize();
	Data *d = deserialize(s);

	std::cout << "Data that were deserialized:" << std::endl;
	std::cout << "d->s1: " << d->s1 << std::endl;
	std::cout << "d->n:  " << d->n << std::endl;
	std::cout << "d->s2: " << d->s2 << std::endl << std::endl;
	
	std::cout << "Data that were, in fact, serialized:" << std::endl;
	std::cout << "s1 control: " << s1_control << std::endl;
	std::cout << "n control:  " << n_control << std::endl;
	std::cout << "s2 control: " << s2_control << std::endl << std::endl;

	std::cout << "Do they match?:" << std::endl;

	std::cout << "s1: " << (d->s1 == s1_control ? "Yes" : "No") << std::endl;
	std::cout << "n:  " << (d->n == n_control ? "Yes" : "No") << std::endl;
	std::cout << "s2: " << (d->s2 == s2_control ? "Yes" : "No") << std::endl;

	delete [] reinterpret_cast<unsigned char *>(s);
	delete d;

	return 0;
}