#include "ScalarConverter.hpp"

// Construtor / Destructor
ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	if (this != &copy)
	{
	}
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

// Other function
void ScalarConverter::convert(const std::string &to_convert)
{
	bool isChar = false;
	bool isFloat = false;
	bool isDouble = false;
	double converted;

    if (to_convert.length() == 1 && !isdigit(to_convert[0]))
	{
        isChar = true;
    }
	else
	{
        char* end;
        converted = std::strtod(to_convert.c_str(), &end);

		// Vérification si c'est un float (se termine par 'f')
        if (*end == 'f' && *(end + 1) == '\0')
            isFloat = true;
        else if (*end == '\0')
            isDouble = true;
	}

    if (isChar)
	{
        std::cout << "char: '" << to_convert[0] << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(to_convert[0]) << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(to_convert[0]) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(to_convert[0]) << std::endl;
    } else if (isFloat || isDouble)
	{
		if (to_convert == "nan" || to_convert == "nanf") {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        } else if (to_convert == "-inf" || to_convert == "-inff") {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        } else if (to_convert == "+inf" || to_convert == "+inff") {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: +inff" << std::endl;
            std::cout << "double: +inf" << std::endl;
        }
		else
		{
			// char
			if (converted < std::numeric_limits<char>::min() || converted > std::numeric_limits<char>::max() || std::isnan(converted))
				std::cout << "char: impossible" << std::endl;
			else if (!isprint(static_cast<char>(converted)))
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: '" << static_cast<char>(converted) << "'" << std::endl;

			// int check error
			if (converted < std::numeric_limits<int>::min() || converted > std::numeric_limits<int>::max() || std::isnan(converted))
				std::cout << "int: impossible" << std::endl;
			else
			{
				// int
				std::cout << "int: " << static_cast<int>(converted) << std::endl;
			}
			// float
			std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(converted) << "f" << std::endl;

			// double
			std::cout << "double: " << converted << std::endl;
		}
	}
	else
        std::cout << "Invalid input" << std::endl;
}
