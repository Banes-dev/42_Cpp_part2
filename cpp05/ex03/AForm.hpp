#pragma once

#include <iostream>
#include "Utils.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
		std::string const _name;
		bool _is_signed;
		int const _mingrade_to_sign;
		int const _mingrade_to_execute;
	public:
		AForm(std::string const &recup_name, int recup_mingrade_to_sign, int recup_mingrade_to_execute);
		AForm(const AForm &copy);
		AForm& operator=(const AForm &copy);
		virtual ~AForm(void) = 0;

		// Other function
		std::string const getName(void) const;
		bool getIsSigned(void) const;
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;

		void beSigned(const Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const &executor) const = 0;

		class GradeTooHighException : public std::exception {
			public :
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &Form);
