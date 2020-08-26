/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entry.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:02:00 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/26 12:48:07 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTRY_HPP
# define ENTRY_HPP
# include "Field.hpp"

class Entry {

public:

	Entry(void);
	int fill_entry(void);
	void print_row(int index);
	void print_single(void);
	int is_filled(void);

public:
	Field first_name;
	Field last_name;
	Field nickname;
	Field login;
	Field postal_address;
	Field email_address;
	Field phone_number;
	Field birthday_date;
	Field favorite_meal;
	Field underwear_color;
	Field darkest_secret;
	int filled;
};

#endif