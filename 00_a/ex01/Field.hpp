/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Field.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 11:59:01 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/26 12:48:02 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIELD_HPP
# define FIELD_HPP

# include <string>
# include <iostream>
# include <iomanip>

class Field {

public:

	int fill_field(void);
	void print_column(void);
	void print_field(void);
	Field(std::string name);

private:

	std::string name;
	std::string value;

};

# endif