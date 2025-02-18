#pragma once

#include <iostream>  	// base
#include <fstream>		// file gestion
#include <sstream>		// text gestion
#include <stack> 		// stack
#include <algorithm> 	// algo

#include "Utils.hpp"


class RPN
{
	private:
		std::stack<int> _stack;

		// bool _ValidateDate(const std::string &date_recup);
		// bool _ValidatePrice(const float price_recup);
		// float _MultiplyResult(const std::string &date, float price) const;
	public:
		RPN(const std::string &recup_argv);
		RPN(const RPN &copy);
		RPN &operator=(const RPN &copy);
		~RPN();

		// Other function
		int getResult(void) const;

		// Exceptions
		class StackEmptyException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("\033[0;31mNot enought numbers\033[0m");
				}
		};
		class StackTooHighException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("\033[0;31mToo many numbers\033[0m");
				}
		};
		class InvalidArgumentException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("\033[0;31mInvalid argument\033[0m");
				}
		};
};
