#pragma once

#include <iostream>

class Form {
    private:
		std::string const _name;
		bool _signed;
		int const _mingrade_to_sign;
		int const _mingrade_to_execute;
	public:
		Form(std::string const &recup_name, int recup_mingrade_to_sign, int recup_mingrade_to_execute);
		~Form(void);

		// Other function
		std::string const getName(void) const;
		bool getSigned(void);
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;

		void signForm(bool value);
		void incrementGradeToSign(int nb);
		void decrementGradeToSign(int nb);
		void incrementGradeToExecute(int nb);
		void decrementGradeToExecute(int nb);

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
