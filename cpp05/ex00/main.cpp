#include "Utils.hpp"

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << std::endl;

	// Grade trop haut
	try {
		Bureaucrat dieu("dieu", 0);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	// Grade trop bas
	try {
		Bureaucrat stagiaire("Stagiaire", 151);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	// normal
	try {
		Bureaucrat cdi("Cdi", 42);

		std::cout << "\n" Yellow << Arrow_down << Cyan <<" Augmenter de grade " << Yellow << Arrow_down << Reset_Color << std::endl;
		std::cout << cdi << std::endl;
		cdi.incrementGrade(1);
		std::cout << cdi << std::endl;
		cdi.incrementGrade(20);
		std::cout << cdi << std::endl;

		std::cout << "\n" Yellow << Arrow_down << Cyan <<" Diminuer de grade " << Yellow << Arrow_down << Reset_Color << std::endl;
		std::cout << cdi << std::endl;
		cdi.decrementGrade(2);
		std::cout << cdi << std::endl;
		cdi.decrementGrade(20);
		std::cout << cdi << std::endl;

		std::cout << "\n" Yellow << Arrow_down << Cyan <<" Exceptions " << Yellow << Arrow_down << Reset_Color << std::endl;
		std::cout << cdi << std::endl;
		cdi.incrementGrade(44);
		// cdi.decrementGrade(130);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	return (0);
}