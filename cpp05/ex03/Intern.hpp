#pragma once

#include <iostream>
#include "Utils.hpp"
#include "AForm.hpp"

class Intern {
    private:
		AForm *makeShrubberyCreationForm(std::string const &target);
		AForm *makeRobotomyRequestForm(std::string const &target);
		AForm *makePresidentialPardonForm(std::string const &target);
	public:
		Intern(void);
		Intern(const Intern &copy);
		Intern& operator=(const Intern &copy);
		~Intern(void);

		// Other function
		AForm *makeForm(std::string const &recup_nameform, std::string const &recup_target);

		class UnknowFormException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
};
