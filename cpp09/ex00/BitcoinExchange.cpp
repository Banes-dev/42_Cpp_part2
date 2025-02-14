#include "BitcoinExchange.hpp"


// Constructor & Destructor
BitcoinExchange::BitcoinExchange(void)
{
	// open data.csv puis definir les valeurs du fichier dans le std::map _list
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

BitcoinExchange::BitcoinExchange &operator=(const BitcoinExchange &copy)
{
	if (this != &copy)
	{
		this->_db = copy._db;
	}
	return (*this);
}

~BitcoinExchange::BitcoinExchange(void)
{
}


// Other function
void BitcoinExchange::addDataForBitcoin(const std::string *recup_input_file)
{
    // open le argv, gestion erreur
    // parser le fichier passer en argument pour qu'il soit au format : date | valeur (date = YYYY-MM-DD, valeur = 0 - 1000 en float/size_t)
	// si tout est bon on renvoie la multiplication de la valeur du bitcoin par la valeur de l'input
}
