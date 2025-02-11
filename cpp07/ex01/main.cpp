#include "Utils.hpp"

#include "iter.hpp"

void printInt(int &i)
{
	std::cout << i << " ";
}

void printChar(char &c)
{
	std::cout << c << " ";
}

int main(void)
{
	int		array[] = {1, 2, 3, 4};
	char	array2[] = {'a', 'b', 'c', 'd', 'e', 'f'};

	iter(array, 4, printInt);
	std::cout << std::endl;

	iter(array2, 6, printChar);
	std::cout << std::endl;

	return (0);
}
