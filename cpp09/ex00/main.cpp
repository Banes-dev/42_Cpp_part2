#include "Utils.hpp"

#include "BitcoinExchange.hpp"

int main(int argc, char**argv)
{
    // check args
    if (argc != 2)
    {
        std::cout << Deny << Red << " Error wrong args\n" << Yellow << "Try : ./btc [input_file.txt]" << Reset_Color << std::endl;
        return (1);
    }

    // create btc
    try {
        BitcoinExchange exchange;
        exchange.addDataForBitcoin(argv[1]);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

	return (0);
}
