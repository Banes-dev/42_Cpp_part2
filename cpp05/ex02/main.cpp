#include "Utils.hpp"

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
// #include "RobotomyRequestForm.hpp"
// #include "PresidentialPardonForm.hpp"

int main(void)
{
	std::cout << std::endl;

	Bureaucrat pdg("PDG", 1);
	Bureaucrat cdi("Cdi", 42);
	Bureaucrat stage("Stagiaire", 140);

	ShrubberyCreationForm form1("Cible 1");
	// RobotomyRequestForm form2("Cible 2");
	// PresidentialPardonForm form3("Cible 3");

	std::cout << pdg << std::endl;
	std::cout << cdi << std::endl;
	std::cout << stage << std::endl;

	std::cout << std::endl;

	// Test ShrubberyCreationForm
	try {
		pdg.executeForm(form1);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		cdi.executeForm(form1);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		stage.executeForm(form1);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		pdg.signForm(form1);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		cdi.signForm(form1);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		stage.signForm(form1);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		pdg.executeForm(form1);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		cdi.executeForm(form1);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		stage.executeForm(form1);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	return (0);
}