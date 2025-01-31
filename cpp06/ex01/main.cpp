#include "Utils.hpp"

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	// if (argc != 2 && argv[1][0] != '\0')
	if (argc != 2)
	{
		std::cout << Deny << Red << " Error wrong args\n" << Yellow << "Try : ./Convert [nb_to_convert]" << Reset_Color << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}