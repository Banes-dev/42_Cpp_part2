#include "Utils.hpp"

#include "easyfind.hpp"

int main(void)
{
	std::vector<size_t> vector;
	vector.push_back(1);
    vector.push_back(2);
    vector.push_back(3);
    vector.push_back(4);
    vector.push_back(42);

	// 1
    try {
        std::vector<size_t>::iterator it = easyfind(vector, 1);
        std::cout << Cyan << "Value found at index " << Yellow << it - vector.begin() << Reset_Color << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // 42
    try {
        std::vector<size_t>::iterator it = easyfind(vector, 42);
        std::cout << Cyan << "Value found at index " << Yellow << it - vector.begin() << Reset_Color << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // 1000
    try {
        std::vector<size_t>::iterator it = easyfind(vector, 1000);
        std::cout << Cyan << "Value found at index " << Yellow << it - vector.begin() << Reset_Color << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

	return (0);
}
