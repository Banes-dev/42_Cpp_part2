#include "Bureaucrat.hpp"

// Construtor / Destructor
Bureaucrat::Bureaucrat(std::string const &recup_name, int recup_grade) : _name(recup_name)
{
	if (recup_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (recup_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = recup_grade;
}

Bureaucrat::~Bureaucrat()
{
}

// Other function
std::string const Bureaucrat::getName(void) const
{
	return (this->_name);
}
int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade(int nb)
{
	if (this->_grade - nb < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade - nb > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = this->_grade - nb;
}
void Bureaucrat::decrementGrade(int nb)
{
	if (this->_grade + nb < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade + nb > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = this->_grade + nb;
}
void Bureaucrat::signForm(AForm &Form)
{
	try {
		Form.beSigned(*this);
		std::cout << this->_name << " sign " << Form.getName() << std::endl;
	} 
	catch (std::exception &e) {
		std::cout << this->_name << " couldn’t sign " << Form.getName() << " because " << e.what() << std::endl;
	}
}
void Bureaucrat::executeForm(AForm const &Form)
{
	try {
		Form.execute(*this);
		std::cout << this->_name << " executed " << Form.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << this->_name << " couldn’t execute " << Form.getName() << " because " << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("\033[0;31mThe grade is too high\033[0m");
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("\033[0;31mThe grade is too low\033[0m");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &Bureaucrat)
{
	out << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade();
	return (out);
}
