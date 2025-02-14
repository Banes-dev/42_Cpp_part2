#pragma once

#include <iostream>  	// base
#include <map> 			// vector
#include <algorithm> 	// algo

#include "Utils.hpp"


class BitcoinExchange
{
	private:
		std::map<std::string, float> _db;
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);
		~BitcoinExchange(void);

		// Other function
		void addDataForBitcoin(const std::string *recup_input_file);

		// Exceptions
		class NotFoundException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("\033[0;31mValue not found in container\033[0m");
				}
		};
};
