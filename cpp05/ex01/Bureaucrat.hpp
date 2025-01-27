#pragma once

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {
    private:
		std::string const _name;
		int _grade;
	public:
		Bureaucrat(std::string const &recup_name, int recup_grade);
		~Bureaucrat(void);

		// Other function
		std::string const getName(void) const;
		int getGrade(void) const;

		void incrementGrade(int nb);
		void decrementGrade(int nb);
		void signForm(Form &Form);

		class GradeTooHighException : public std::exception {
			public :
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &Bureaucrat);
