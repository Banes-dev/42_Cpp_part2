#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// function private
AForm *Intern::makeShrubberyCreationForm(std::string const &target)
{
	std::cout << "Intern creates a shrubbery creation form" << std::endl;
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomyRequestForm(std::string const &target)
{
	std::cout << "Intern creates a robotomy request form" << std::endl;
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresidentialPardonForm(std::string const &target)
{
	std::cout << "Intern creates a presidential pardon form" << std::endl;
	return (new PresidentialPardonForm(target));
}

// Construtor / Destructor
Intern::Intern()
{
}

Intern::Intern(const Intern &copy)
{
	*this = copy;
}

Intern &Intern::operator=(const Intern &copy)
{
	if (this != &copy)
	{
	}
	return (*this);
}

Intern::~Intern()
{
}

// Other function
AForm *Intern::makeForm(std::string const &recup_nameform, std::string const &recup_target)
{
	AForm *(Intern::*list_form[3])(std::string const &) = {
		&Intern::makeShrubberyCreationForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm
	};
	std::string	list_nameform[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	int i = 0;
	while (i < 3)
	{
		if (recup_nameform == list_nameform[i])
			return (this->*list_form[i])(recup_target);
		i++;
	}
	throw Intern::UnknowFormException();
}

const char *Intern::UnknowFormException::what() const throw()
{
	return ("\033[0;31mThe form is unknown\033[0m");
}
