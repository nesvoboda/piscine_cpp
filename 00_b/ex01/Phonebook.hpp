#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include <string>
# include <iostream>
# include <iomanip>
# include "Entry.hpp"

class Phonebook {

public:
	void add_entry(void);
	void search(void);
	void print_table_head(void);
	void horisontal_divider(void);
	void pretty_print(std::string word);
	void retrieve(int index);

private:
	Entry contents[8];
};

#endif