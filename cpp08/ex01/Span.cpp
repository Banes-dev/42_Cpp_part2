#include "Span.hpp"


// Construtor / Destructor
Span::Span(size_t recup_max) : _max(recup_max)
{
}

Span::Span(const Span &copy)
{
	*this = copy;
}

Span &Span::operator=(const Span &copy)
{
	if (this != &copy)
	{
		this->_list = copy._list;
		this->_max = copy._max;
	}
	return (*this);
}

Span::~Span(void)
{
}


// Other function
void Span::addNumber(int recup_number)
{
	if (this->_list.size() >= this->_max)
		throw (MaxValueException());
	this->_list.push_back(recup_number);
}

int Span::shortestSpan(void) const
{
	if (this->_list.size() < 2)
		throw (NoEnoughException());
	std::vector<int> tmp = this->_list;
	std::sort(tmp.begin(), tmp.end());

	int min = tmp[1] - tmp[0];
	size_t i = 1;
	while (i < tmp.size())
	{
		if ((tmp[i] - tmp[i - 1]) < min)
			min = (tmp[i] - tmp[i - 1]);
		i++;
	}
	return (min);
}

int Span::longestSpan(void) const
{
	if (this->_list.size() < 2)
		throw (NoEnoughException());
	std::vector<int>::const_iterator min = std::min_element(this->_list.begin(), this->_list.end());
    std::vector<int>::const_iterator max = std::max_element(this->_list.begin(), this->_list.end());
	return (*max - *min);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (this->_list.size() + std::distance(begin, end) > this->_max)
		throw (MaxValueException());
	this->_list.insert(this->_list.end(), begin, end);
}


// Exceptions
const char *Span::MaxValueException::what() const throw()
{
	return ("\033[0;31mThe container can't have more number\033[0m");
}
const char *Span::NoEnoughException::what() const throw()
{
	return ("\033[0;31mNo enought number stored\033[0m");
}
