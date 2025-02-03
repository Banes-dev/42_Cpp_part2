#pragma once

#include <iostream>

#include "Utils.hpp"

class Data {
    private:
		int _value;
	public:
		Data(int recup_value);
		Data(const Data &copy);
		Data &operator=(const Data &copy);
		virtual ~Data(void);

		// Other function
		int getValue(void) const;
		void setValue(int recup_value);
};
