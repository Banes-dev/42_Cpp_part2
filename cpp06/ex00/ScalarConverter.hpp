#pragma once

#include <iostream>
#include <cstdlib>

#include <sstream>
#include <iomanip>
#include <limits>
#include <cmath>

#include "Utils.hpp"

class ScalarConverter
{
    private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &copy);
	public:
		virtual ~ScalarConverter(void) = 0;

		// Other function
		static void convert(const std::string &to_convert);
};
