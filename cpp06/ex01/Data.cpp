#include "Data.hpp"

// Construtor / Destructor
Data::Data(int recup_value) : _value(recup_value)
{
}

Data::Data(const Data &copy)
{
	*this = copy;
}

Data &Data::operator=(const Data &copy)
{
	if (this != &copy)
	{
	}
	return (*this);
}

Data::~Data()
{
}

// Other function
int Data::getValue(void) const
{
	return (this->_value);
}

void Data::setValue(int recup_value)
{
	this->_value = recup_value;
}
