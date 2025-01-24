#include "Utils.hpp"
#include "Form.hpp"
#include <string>

// Construtor / Destructor
Form::Form(std::string const &recup_name, int recup_grade) : _name(recup_name)
{
	if (recup_grade < 1)
		throw Form::GradeTooHighException();
	if (recup_grade > 150)
		throw Form::GradeTooLowException();
	this->_grade = recup_grade;
}

Form::~Form()
{
}

// Other function
std::string const Form::getName(void) const
{
	return (this->_name);
}
int Form::getGrade(void) const
{
	return (this->_grade);
}

void Form::incrementGrade(int nb)
{
	if (this->_grade - nb < 1)
		throw Form::GradeTooHighException();
	if (this->_grade - nb > 150)
		throw Form::GradeTooLowException();
	this->_grade = this->_grade - nb;
}
void Form::decrementGrade(int nb)
{
	if (this->_grade + nb < 1)
		throw Form::GradeTooHighException();
	if (this->_grade + nb > 150)
		throw Form::GradeTooLowException();
	this->_grade = this->_grade + nb;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("\033[0;31mThe grade is too high\033[0m");
}
const char *Form::GradeTooLowException::what() const throw()
{
	return ("\033[0;31mThe grade is too low\033[0m");
}

std::ostream &operator<<(std::ostream &out, const Form &Form)
{
	out << Form.getName() << ", Form grade " << Form.getGrade();
	return (out);
}
