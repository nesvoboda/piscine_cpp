#include "phonebook.hpp"

int main(void)
{
	std::string buffer;
	Phonebook book;

	std::cout << "Hello! This is the phonebook. It can:" 
	 << std::endl
	 << std::endl << "ADD       add a contact"
	 << std::endl << "SEARCH    show all contacts and examine a single contact"
	 << std::endl << "EXIT      close the program" << std::endl
	 << std::endl << "Please enter a command:" << std::endl << std::endl;
	while (1)
	{
		std::cout << "> ";
		std::getline(std::cin, buffer);
		if (buffer == "ADD")
		{
			book.add_entry();
		}
		else if (buffer == "SEARCH")
		{
			book.search();
		}
		else if (buffer == "EXIT")
		{
			return (0);
		}
		else
		{
			std::cout << std::endl 
			<< "This isn't a command :(. Try this:" << std::endl
			<< std::endl << "ADD       adds a contact"
	 		<< std::endl << "SEARCH    lets you examine a contact"
	 		<< std::endl << "EXIT      closes the program" << std::endl
	 		<< std::endl;
		}
	}
}