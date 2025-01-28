#pragma once

#include <iostream>
#include <fstream>
#include "Utils.hpp"
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		std::string const _target;
	public:
		ShrubberyCreationForm(std::string const &recup_target);
		virtual ~ShrubberyCreationForm(void);

		// Other function
		std::string const getTarget(void) const;
		void execute(Bureaucrat const &executor) const;

		class GradeTooLowForExecutionException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
		class NotSignedException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
		class FileNotOpenException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
};
