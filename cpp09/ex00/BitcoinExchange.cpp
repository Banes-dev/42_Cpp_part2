#include "BitcoinExchange.hpp"


// Constructor & Destructor
BitcoinExchange::BitcoinExchange(void)
{
	std::ifstream file_db("data.csv");
	if (!file_db)
		throw NoOpenFileException();

	std::string line;
	std::getline(file_db, line);
	if (line != "date,exchange_rate")
        throw InvalidFormatException();
	while (std::getline(file_db, line))
	{
		std::string date, price;
        std::istringstream ss(line);
        std::getline(ss, date, ',');
        std::getline(ss, price, ',');

        // Parse price using istringstream
        float price_convert;
        std::istringstream price_stream(price);
        if (!(price_stream >> price_convert))
			throw InvalidPriceDbException();
		
		// save info
        _db[date] = price_convert;
	}
	file_db.close();
	// std::cout << _db << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	if (this != &copy)
	{
		this->_db = copy._db;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
}


// Other function
void BitcoinExchange::addDataForBitcoin(const std::string &recup_input_file)
{
	// (void)recup_input_file;
    // open le argv, gestion erreur
    // parser le fichier passer en argument pour qu'il soit au format : date | valeur (date = YYYY-MM-DD, valeur = 0 - 1000 en float/size_t)
	// si tout est bon on renvoie la multiplication de la valeur du bitcoin par la valeur de l'input

	std::ifstream file_input(recup_input_file.c_str());
	if (!file_input)
		throw NoOpenFileException();

	std::string line;
	std::getline(file_input, line);
	if (line != "date | value")
        throw InvalidFormatException();
	while (std::getline(file_input, line))
	{
		std::string date;
		std::string value;
		std::istringstream ss(line);
		std::getline(ss >> std::ws, date, '|');
		date.erase(date.find_last_not_of(" \t\r\n") + 1);
		std::getline(ss >> std::ws, value, '|');
		value.erase(value.find_last_not_of(" \t\r\n") + 1);

		// Validate date format.
		if (_ValidateDate(date) == false)
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		// Parse price using istringstream
        float price;
        std::istringstream price_stream(value);
        if (!(price_stream >> price))
		{
			std::cout << "Error: bad input => " << value << std::endl;
			continue;
		}
		if (_ValidatePrice(price) == true)
			std::cout << date << " => " << price << " = " <<  _MultiplyResult(date, price) << std::endl;
	}
	file_input.close();
}

bool BitcoinExchange::_ValidateDate(const std::string &date_recup)
{
	if (date_recup.size() != 10 || date_recup[4] != '-' || date_recup[7] != '-')
		return (false);
	// check si digit
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (isdigit(date_recup[i]) == 0)
			return (false);
	}
	// Extraire l'année, le mois et le jour de la date
	int year, month, day;
	std::stringstream(date_recup.substr(0, 4)) >> year;
	std::stringstream(date_recup.substr(5, 2)) >> month;
	std::stringstream(date_recup.substr(8, 2)) >> day;
    // Vérifier la validité du mois
    if (month < 1 || month > 12)
        return (false);
    // Vérifier la validité du jour selon le mois
    int daysInMonth;
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        daysInMonth = 31;
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        daysInMonth = 30;
    else if (month == 2)
    {
        if ((year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
            daysInMonth = 29;  // Année bissextile, février a 29 jours
        else
            daysInMonth = 28;  // Année non-bissextile, février a 28 jours
    }
    // Vérifier si le jour est valide pour le mois donné
    if (day < 1 || day > daysInMonth)
	{
		return (false);
	}
	return (true);
}

bool BitcoinExchange::_ValidatePrice(const float price_recup)
{
	if (price_recup < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (false);
	}
	else if (price_recup > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return (false);
	}

	return (true);
}

float BitcoinExchange::_MultiplyResult(const std::string& date, float price) const
{
	std::map<std::string, float>::const_iterator it = this->_db.find(date);
	if (it == this->_db.end())
	{
		std::map<std::string, float>::const_iterator it2 = this->_db.lower_bound(date);
		if (it2 != this->_db.begin())
		{
			it2--;
			return (it2->second * price);
		}
		return (it2->second * price);
	}
	return (it->second * price);
}
