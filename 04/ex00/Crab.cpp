#include "Crab.hpp"

Crab::Crab(std::string new_name) : Victim(new_name)
{
	std::cout << "Click click." << std::endl;
}

Crab::Crab(const Crab &copy) : Victim(copy)
{
}

Crab& Crab::operator= (const Crab &operand)
{
	Victim::operator=(operand);
	return (*this);
}

Crab::~Crab()
{
	std::cout << "Bshhhh" << std::endl;
}

void Crab::getPolymorphed(void) const
{
	std::cout << this->getName() << " has been turned into a turtle!"
	<< std::endl;
}
