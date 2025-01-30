#pragma once

#include <iostream>

class ScalarConverter {
    private:
	public:
		ScalarConverter(void);
		virtual ~ScalarConverter(void) = 0;

		// Other function
		void decrementGrade(int nb);
};
