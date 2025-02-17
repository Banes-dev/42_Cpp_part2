#include "Utils.hpp"

#include "BitcoinExchange.hpp"

int main(int argc, char**argv)
{
    // check args
    if (argc != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
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
