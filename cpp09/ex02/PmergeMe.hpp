#pragma once

#include <iostream>  	// base
#include <fstream>		// file gestion
#include <sstream>		// text gestion
#include <vector> 		// vector
#include <deque> 		// deque
#include <algorithm> 	// algo
#include <ctime>		// time

#include "Utils.hpp"


class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &copy);
		~PmergeMe();

		// Other function
		static std::vector<size_t> ConvertVector(char **args);
		static std::deque<size_t> ConvertDeque(char **args);
		
		static const std::vector<size_t> VectorTime(std::vector<size_t> list, double &time);
		static const std::deque<size_t> DequeTime(std::deque<size_t> list, double &time);
		
		static void PrintVector(const std::vector<size_t> &list);
		static void PrintDeque(const std::deque<size_t> &list);

		// Utils function
		static std::vector<size_t> VectorSort(std::vector<size_t> list);
		static std::deque<size_t> DequeSort(std::deque<size_t> list);

		static bool VectorIsSorted(std::vector<size_t> &list);
		static bool DequeIsSorted(std::deque<size_t> &list);

		// Exceptions
		class StackEmptyException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("\033[0;31mNot enought numbers\033[0m");
				}
		};
};
