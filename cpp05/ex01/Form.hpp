#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private:
		std::string const _name;
		bool _is_signed;
		int const _mingrade_to_sign;
		int const _mingrade_to_execute;
	public:
		Form(std::string const &recup_name, int recup_mingrade_to_sign, int recup_mingrade_to_execute);
		Form(const Form &copy);
		Form& operator=(const Form &copy);
		~Form(void);

		// Other function
		std::string const getName(void) const;
		bool getIsSigned(void) const;
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;

		void beSigned(const Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception {
			public :
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Form &Form);
