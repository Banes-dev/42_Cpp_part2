#include "RobotomyRequestForm.hpp"

// Construtor / Destructor
RobotomyRequestForm::RobotomyRequestForm(std::string const &recup_target) : AForm("RobotomyRequestForm", 72, 45), _target(recup_target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

// Other function
std::string const RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() >  this->getGradeToExecute())
		throw RobotomyRequestForm::GradeTooLowForExecutionException();
	if (this->getIsSigned() == false)
		throw RobotomyRequestForm::NotSignedException();
	std::cout << "Drrrrr Drrrrr Drrrrr" << std::endl;
	std::srand(std::time(0) + std::rand());
	if (std::rand() % 2 == 0)
		std::cout << this->_target << Green << " has been robotomized" << Reset_Color << std::endl;
	else
		std::cout << this->_target << Red << " failed to be robotomized" << Reset_Color << std::endl;
}

const char *RobotomyRequestForm::GradeTooLowForExecutionException::what() const throw()
{
	return ("\033[0;31mThe grade is too low\033[0m");
}
const char *RobotomyRequestForm::NotSignedException::what() const throw()
{
	return ("\033[0;31mThe form is not signed\033[0m");
}
