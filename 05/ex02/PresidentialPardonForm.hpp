/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 21:42:10 by ashishae          #+#    #+#             */
/*   Updated: 2020/10/02 15:06:06 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Bureaucrat.hpp"
# include "Form.hpp"
# include <string>

class PresidentialPardonForm : public Form {

public:
	PresidentialPardonForm(std::string target);
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	PresidentialPardonForm &operator= (const PresidentialPardonForm &operand);
	void execute(Bureaucrat const &executor) const;

private:
	PresidentialPardonForm();
	std::string target;

};

#endif