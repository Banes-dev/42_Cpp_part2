#include "Utils.hpp"
#include "ScalarConverter.hpp"

// Construtor / Destructor
ScalarConverter::ScalarConverter(std::string const &recup_name, int recup_grade) : _name(recup_name)
{
	if (recup_grade < 1)
		throw ScalarConverter::GradeTooHighException();
	if (recup_grade > 150)
		throw ScalarConverter::GradeTooLowException();
	this->_grade = recup_grade;
}

ScalarConverter::~ScalarConverter()
{
}

// Other function
std::string const ScalarConverter::getName(void) const
{
	return (this->_name);
}
int ScalarConverter::getGrade(void) const
{
	return (this->_grade);
}

void ScalarConverter::incrementGrade(int nb)
{
	if (this->_grade - nb < 1)
		throw ScalarConverter::GradeTooHighException();
	if (this->_grade - nb > 150)
		throw ScalarConverter::GradeTooLowException();
	this->_grade = this->_grade - nb;
}
void ScalarConverter::decrementGrade(int nb)
{
	if (this->_grade + nb < 1)
		throw ScalarConverter::GradeTooHighException();
	if (this->_grade + nb > 150)
		throw ScalarConverter::GradeTooLowException();
	this->_grade = this->_grade + nb;
}

const char *ScalarConverter::GradeTooHighException::what() const throw()
{
	return ("\033[0;31mThe grade is too high\033[0m");
}
const char *ScalarConverter::GradeTooLowException::what() const throw()
{
	return ("\033[0;31mThe grade is too low\033[0m");
}

std::ostream &operator<<(std::ostream &out, const ScalarConverter &ScalarConverter)
{
	out << ScalarConverter.getName() << ", ScalarConverter grade " << ScalarConverter.getGrade();
	return (out);
}
