#include "mapBtc.hpp"

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
	std::cout << "Destructor of mapBtc called\n";
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

void mapBtc::checkMap()
{
	for (std::map<std::string, float>::iterator it = _map.begin(); it != _map.end(); it++)
	{
		if (!checkFormat(it->first))
			continue;
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

void mapBtc::checkKey(std::string key)
{
	(void)key;
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
	if (i != 2 || (int)key.size() != j + i || checkDays(key.substr(j, 2)))
		return (logError("bad input => " + key));
	days = atoi(key.substr(j, 2).c_str());
	if (!checkDates(years, months, days))
		return (logError("bad input => " + key));
	return (true);
}

const char *mapBtc::FileNotExist::what() const throw()
{
	return ("File Not Exist\n");
}

const char *mapBtc::BadFormat::what() const throw()
{
	return ("Bad Format\n");
}
