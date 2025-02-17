#pragma once

#include <iostream>  	// base
#include <fstream>		// file gestion
#include <sstream>		// text gestion
#include <map> 			// vector
#include <algorithm> 	// algo

#include "Utils.hpp"


class BitcoinExchange
{
	private:
		std::map<std::string, float> _db;

		bool _ValidateDate(const std::string &date_recup);
		bool _ValidatePrice(const float price_recup);
		float _MultiplyResult(const std::string &date, float price) const;
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);
		~BitcoinExchange(void);

		// Other function
		void addDataForBitcoin(const std::string &recup_input_file);

		// Exceptions
		class NoOpenFileException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Error: could not open file.");
				}
		};
		class InvalidFormatException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("\033[0;31mInvalid format on your db, exemple : 'date,exchange_rate'\033[0m");
				}
		};
		class InvalidPriceDbException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("\033[0;31mInvalid price format on your db, exemple : number between 0.0 and 1000.0\033[0m");
				}
		};
		class InvalidPriceInputException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("\033[0;31mInvalid price format on your input, exemple : number between 0.0 and 1000.0\033[0m");
				}
		};
};
