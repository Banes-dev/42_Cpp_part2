#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Utils.hpp"
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		std::string const _target;
	public:
		RobotomyRequestForm(std::string const &recup_target);
		virtual ~RobotomyRequestForm(void);

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
};
