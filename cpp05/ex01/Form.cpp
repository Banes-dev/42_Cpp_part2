#include "Utils.hpp"
#include "Form.hpp"

// Construtor / Destructor
Form::Form(std::string const &recup_name, int recup_mingrade_to_sign, int recup_mingrade_to_execute) : _name(recup_name), _is_signed(false), _mingrade_to_sign(recup_mingrade_to_sign), _mingrade_to_execute(recup_mingrade_to_execute)
{
	// this->_is_signed = false;

	// if (recup_mingrade_to_sign < 1)
	// 	throw Form::GradeTooHighException();
	// if (recup_mingrade_to_sign > 150)
	// 	throw Form::GradeTooLowException();
	// this->_mingrade_to_sign = recup_mingrade_to_sign;

	// if (recup_mingrade_to_execute < 1)
	// 	throw Form::GradeTooHighException();
	// if (recup_mingrade_to_execute > 150)
	// 	throw Form::GradeTooLowException();
	// this->_mingrade_to_execute = recup_mingrade_to_execute;
}

Form::Form(const Form &copy) : _name(copy._name), _is_signed(copy._is_signed), _mingrade_to_sign(copy._mingrade_to_sign), _mingrade_to_execute(copy._mingrade_to_execute)
{
	// std::cout << "Copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &copy)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_name = copy._name;
	this->_is_signed = copy._is_signed;
	this->_mingrade_to_sign = copy._mingrade_to_sign;
	this->_mingrade_to_execute = copy._mingrade_to_execute;
	return (*this);
}

Form::~Form()
{
}

// Other function
std::string const Form::getName(void) const
{
	return (this->_name);
}
bool Form::getIsSigned(void) const
{
	return (this->_is_signed);
}
int Form::getGradeToSign(void) const
{
	return (this->_mingrade_to_sign);
}
int Form::getGradeToExecute(void) const
{
	return (this->_mingrade_to_execute);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_mingrade_to_sign)
		throw Form::GradeTooLowException();
	this->_is_signed = true;
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
	out << Form.getName() << " is ";
	if (Form.getIsSigned())
		out << "signed";
	else
		out << "not signed";
	out << " and need grade " << Form.getGradeToSign() << " to be signed and grade " << Form.getGradeToExecute() << " to be executed";
	return (out);
}
