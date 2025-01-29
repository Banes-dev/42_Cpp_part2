#include "Utils.hpp"

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	std::cout << std::endl;

	Bureaucrat pdg("PDG", 1);
	Bureaucrat stage("Stagiaire", 150);

	std::cout << pdg << std::endl;
	std::cout << stage << std::endl;

	std::cout << std::endl;

	Intern intern;

	AForm	*shrubberyCreationForm = intern.makeForm("shrubbery creation", "Cible1");
	AForm	*robotomyRequestForm = intern.makeForm("robotomy request", "Cible2");
	AForm	*presidentialPardonForm = intern.makeForm("presidential pardon", "Cible3");

	// Intern Exception
	try {
		AForm	*test = intern.makeForm("test", "Cible test");
		delete test;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	pdg.executeForm(*presidentialPardonForm);
	pdg.executeForm(*robotomyRequestForm);
	pdg.executeForm(*shrubberyCreationForm);
	stage.executeForm(*presidentialPardonForm);
	stage.executeForm(*robotomyRequestForm);
	stage.executeForm(*shrubberyCreationForm);
	std::cout << std::endl;

	pdg.signForm(*presidentialPardonForm);
	pdg.signForm(*robotomyRequestForm);
	pdg.signForm(*shrubberyCreationForm);
	stage.signForm(*presidentialPardonForm);
	stage.signForm(*robotomyRequestForm);
	stage.signForm(*shrubberyCreationForm);
	std::cout << std::endl;

	pdg.executeForm(*presidentialPardonForm);
	pdg.executeForm(*robotomyRequestForm);
	pdg.executeForm(*shrubberyCreationForm);
	stage.executeForm(*presidentialPardonForm);
	stage.executeForm(*robotomyRequestForm);
	stage.executeForm(*shrubberyCreationForm);
	std::cout << std::endl;

	delete presidentialPardonForm;
	delete robotomyRequestForm;
	delete shrubberyCreationForm;
	return (0);
}