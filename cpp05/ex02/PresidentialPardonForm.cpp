#include "PresidentialPardonForm.hpp"

// Construtor / Destructor
PresidentialPardonForm::PresidentialPardonForm(std::string const &recup_target) : AForm("PresidentialPardonForm", 25, 5), _target(recup_target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

// Other function
std::string const PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() >  this->getGradeToExecute())
		throw PresidentialPardonForm::GradeTooLowForExecutionException();
	if (this->getIsSigned() == false)
		throw PresidentialPardonForm::NotSignedException();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

const char *PresidentialPardonForm::GradeTooLowForExecutionException::what() const throw()
{
	return ("\033[0;31mThe grade is too low\033[0m");
}
const char *PresidentialPardonForm::NotSignedException::what() const throw()
{
	return ("\033[0;31mThe form is not signed\033[0m");
}
