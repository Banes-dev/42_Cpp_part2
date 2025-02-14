#pragma once

#include <iostream>  	// base
#include <vector> 		// vector
#include <deque> 		// deque
#include <list> 		// list
#include <algorithm> 	// algo

#include "Utils.hpp"


class Span
{
    private:
		size_t _max;
		std::vector<int> _list;
	public:
		Span(size_t recup_max);
		Span(const Span &copy);
		Span &operator=(const Span &copy);
		~Span(void);

		// Other function
		void addNumber(int recup_number);
		int shortestSpan(void) const;
		int longestSpan(void) const;
		void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		// Exceptions
		class MaxValueException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class NoEnoughException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};
