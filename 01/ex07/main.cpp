/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 14:00:29 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/29 18:50:05 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <iostream>

void replaceAll(std::string &where, std::string old, std::string new_str)
{
	size_t current_position = 0;

	while ((current_position = where.find(old, current_position)) !=
				std::string::npos)
	{
		where.replace(current_position, old.length(), new_str);
		// The following line prevents the program from going into an infinite
		// loop if new_str contains old.
		current_position += new_str.length();
	}
}

int main(int ac, char const *av[])
{
	if (ac != 4)
	{
		std::cout << "Usage: ./replace <filename> <string_to_replace> <new string>" << std::endl;
		return 1;
	}
	std::ifstream infile;
	std::ofstream outfile;
	std::string outfile_name;

	infile.open(av[1]);
	if (!infile.is_open())
	{
		std::cout << "Can't open the initial file :(" << std::endl;
		return 1;
	}
	outfile_name.assign(av[1]);

	outfile_name += ".replace";

	outfile.open(outfile_name);
	if (!outfile.is_open())
	{
		std::cout << "Can't create a new file to write the output :(" << std::endl;
		return 1;
	}

	std::string line;
	while (getline(infile,line))
	{
		replaceAll(line, av[2], av[3]);
		outfile << line;
		if (!infile.eof())
			outfile << std::endl;
	}
	infile.close();
	outfile.close();

	return 0;
}