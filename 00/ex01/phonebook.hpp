#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include <string>

class Entry {

public:

	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string login;
	std::string postal_address;
	std::string email_address;
	std::string phone_number;
	std::string birthday_date;
	std::string favorite_meal;
	std::string underwear_color;
	std::string darkest_secret;

	Entry(void);
	~Entry(void);
	void fill_entry(void);
};

class Field {

public:

	std::string name;
	std::string value;

	Field(std::string name);
	~Field(void);
	void fill_field(void);
};

#endif