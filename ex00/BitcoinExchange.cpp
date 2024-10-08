#include "BitcoinExchange.hpp"

mapBtc::mapBtc()
{
	// std::cout << "mapBtc default constructor called\n";
}

mapBtc::mapBtc(const mapBtc &obj)
{
	std::cout << "Copy constructor called\n";
	*this = obj;
	return;
}

mapBtc &mapBtc::operator=(const mapBtc &obj)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &obj)
	{
	}
	return *this;
}

mapBtc::~mapBtc()
{
}

void mapBtc::fillMap()
{
	std::string tmp;
	std::string key;
	float value = 0;
	std::ifstream file("data.csv");
	if (!file.good())
		throw FileNotExist();
	std::getline(file, tmp);
	while (std::getline(file, tmp))
	{
		key = tmp.substr(0, tmp.find(','));
		std::stringstream svalue(tmp.substr(tmp.find(',') + 1, tmp.size()));
		svalue >> value;
		_map.insert(std::make_pair(key, value));
	}
}

void mapBtc::printMap()
{
	for (std::map<std::string, float>::iterator it = _map.begin(); it != _map.end(); it++)
	{
		std::cout << std::fixed << std::setprecision(2);
		std::cout << "Date: " << it->first << " Price: " << it->second << std::endl;
	}
}

void mapBtc::printPrice(std::string path)
{
	std::string tmp;
	std::string date;
	float price;
	float amount;
	std::ifstream file(path.c_str());
	if (!file.good())
		throw FileNotExist();
	std::getline(file, tmp);
	while (std::getline(file, tmp))
	{
		if (!checkFormat(tmp))
			continue;
		date = tmp.substr(0, tmp.find('|') - 1);
		price = getPrice(date);
		std::stringstream svalue(tmp.substr(tmp.find('|') + 1, tmp.size()));
		svalue >> amount;
		std::cout << date << " => " << amount << " = " << price * amount << std::endl;
	}
}

bool mapBtc::checkYears(std::string key)
{
	if (atoi(key.c_str()) > 2024 || atoi(key.c_str()) < 2009)
		return (true);
	return (false);
}

bool mapBtc::checkMonths(std::string key)
{
	if (atoi(key.c_str()) > 12 || atoi(key.c_str()) < 1)
		return (true);
	return (false);
}

bool mapBtc::checkDays(std::string key)
{
	if (atoi(key.c_str()) > 31 || atoi(key.c_str()) < 1)
		return (true);
	return (false);
}

float mapBtc::getPrice(std::string key)
{
	std::map<std::string, float>::iterator it = _map.lower_bound(key);

	if (it == _map.end() || it->first != key)
	{
		if (it == _map.begin())
			return (0.00);
		--it;
	}
	return (it->second);
}

bool mapBtc::checkDates(int years, int months, int days)
{
	if (months == 2 && days == 29 && years % 4 != 0)
		return (false);
	if (months == 2 && days > 28)
		return (false);
	if ((months == 4 || months == 6 || months == 9 || months == 11) && days > 30)
		return (false);
	std::time_t currentTime = std::time(0);
	std::tm *currentDate = std::localtime(&currentTime);
	int currentYear = currentDate->tm_year + 1900;
	int currentMonth = currentDate->tm_mon + 1;
	int currentDay = currentDate->tm_mday;

	if (years > currentYear || (years == currentYear && months > currentMonth) || (years == currentYear && months == currentMonth && days > currentDay))
		return (false);
	return (true);
}

bool logError(std::string str)
{
	std::cout << "Error: " << str << std::endl;
	return (false);
}

bool mapBtc::checkValue(std::string key)
{
	float value;
	std::stringstream svalue(key.substr(key.find('|') + 1, key.size()));

	if (svalue.fail())
		return (logError("Fail to convert value => " + key));
	svalue >> value;
	if (value < 0 || value > 1000)
		return (logError("Value to small or to big => " + key));
	return (true);
}

bool mapBtc::checkFormat(std::string key)
{
	int i = 0;
	int j = 0;
	int years;
	int months;
	int days;

	while (isdigit(key[i + j]))
		i++;
	if (i != 4 || key[j + i++] != '-' || checkYears(key.substr(0, 4)))
		return (logError("bad input => " + key));
	years = atoi(key.substr(0, 4).c_str());
	j += i;
	i = 0;
	while (isdigit(key[i + j]))
		i++;
	if (i != 2 || key[j + i++] != '-' || checkMonths(key.substr(j, 2)))
		return (logError("bad input => " + key));
	months = atoi(key.substr(j, 2).c_str());
	j += i;
	i = 0;
	while (isdigit(key[i + j]))
		i++;
	if (i != 2 || key[j + i + 1] != '|' || key[j + i + 2] != ' ' || checkDays(key.substr(j, 2)))
		return (logError("bad input => " + key));
	days = atoi(key.substr(j, 2).c_str());
	if (!checkDates(years, months, days))
		return (logError("bad input => " + key));
	if (!checkValue(key))
		return (false);
	return (true);
}

std::map<std::string, float> mapBtc::getMap()
{
	return (_map);
}

const char *mapBtc::FileNotExist::what() const throw()
{
	return ("File Not Exist\n");
}
