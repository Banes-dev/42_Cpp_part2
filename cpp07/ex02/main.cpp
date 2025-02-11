#include "Utils.hpp"

#include "Array.hpp"
#include "Array.tpp"


int main(void)
{
    // Int
    Array<int> intArray(5);
    for (size_t i = 0; i < intArray.size(); i++) {
        intArray[i] = i + 1;
    }
    std::cout << Cyan << "Integer Array : " << Yellow;
    for (size_t i = 0; i < intArray.size(); i++) {
        std::cout << intArray[i] << " ";
    }
    std::cout << Reset_Color << std::endl;

    // Character
    Array<char> charArray(3);
    charArray[0] = 'A';
    charArray[1] = 'B';
    charArray[2] = 'C';
    std::cout << Cyan << "Character Array : " << Yellow;
    for (size_t i = 0; i < charArray.size(); i++) {
        std::cout << charArray[i] << " ";
    }
    std::cout << Reset_Color << std::endl;

    // None
    Array<double> doubleArray;
    std::cout << Cyan << "Double Array size : " << Yellow << doubleArray.size() << Reset_Color << std::endl;

    return (0);
}
