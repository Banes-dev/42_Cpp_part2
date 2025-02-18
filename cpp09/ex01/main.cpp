#include "Utils.hpp"

#include "RPN.hpp"

int main(int argc, char**argv)
{
    // check args
    if (argc != 2)
    {
        std::cout << Deny << Red << "Error wrong args\n" << Yellow << "Try : ./RPN \"operation\"" << Reset_Color << std::endl;
        return (1);
    }

    // create btc
    try {
        RPN rpn(argv[1]);
        std::cout << Cyan << "Result : " << Yellow << rpn.getResult() << Reset_Color << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

	return (0);
}
