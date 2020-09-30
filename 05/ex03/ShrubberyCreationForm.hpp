/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 12:59:27 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/29 19:58:37 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"
# include <iostream>
# include <fstream>

class ShrubberyCreationForm : public Form {

public:
	ShrubberyCreationForm(std::string target);
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	ShrubberyCreationForm &operator= (const ShrubberyCreationForm &operand);
	void execute(Bureaucrat const &executor) const;

	static Form *create(std::string target);

	class FileErrorException: public std::exception {
		public:
			virtual const char* what() const throw();
	};

private:
	ShrubberyCreationForm();
	std::string target;

};

#endif