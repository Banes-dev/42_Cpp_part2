#include "Utils.hpp"

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << std::endl;

	Bureaucrat pdg("PDG", 1);
	Bureaucrat cdi("Cdi", 42);
	Bureaucrat stage("Stagiaire", 150);

	Form form1("Formulaire 1", 1, 1);
	Form form2("Formulaire 2", 42, 42);
	Form form3("Formulaire 3", 150, 150);

	std::cout << pdg << std::endl;
	std::cout << cdi << std::endl;
	std::cout << stage << std::endl;

	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;
	std::cout << form3 << std::endl;

	std::cout << std::endl;

	// excetpion form
	try {
		Form form("test1", 0, 42);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Form form("test2", 151, 42);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
		try {
		Form form("test3", 42, 0);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Form form("test4", 42, 151);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	// signform
	try {
		pdg.signForm(form1);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		pdg.signForm(form2);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
		try {
		pdg.signForm(form3);
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
		cdi.signForm(form2);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
		try {
		cdi.signForm(form3);
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
	try {
		stage.signForm(form2);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		stage.signForm(form3);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	return (0);
}