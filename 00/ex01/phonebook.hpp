#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include <string>
# include <iostream>

class Field {

public:

	std::string name;
	std::string value;

	Field(std::string name);
	~Field(void);
	void fill_field(void);
	void print_column(int border);
	void print_field(void);
};


class Entry {

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

	Entry(void);
	~Entry(void);
	void fill_entry(void);
	void print_row(int index);
	void print_single(void);
};


class Phonebook {

public:
	Entry contents[8];

	Phonebook(void);
	void add_entry(void);
	void search(void);
	void print_table_head(void);
	void horisontal_divider(void);
	void pretty_print(std::string word);
	void retrieve(int index);
};

#endif