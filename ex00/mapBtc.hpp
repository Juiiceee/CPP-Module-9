#ifndef MAPBTC_HPP
#define MAPBTC_HPP
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <iomanip>

class mapBtc
{
private:
	std::map<std::string, float> _map;
	bool checkYears(std::string key);
	bool checkMonths(std::string key);
	bool checkDays(std::string key);
	bool checkDates(int years, int months, int days);
	bool checkValue(std::string key);
	float getPrice(std::string key);
	bool checkFormat(std::string key);

public:
	void printPrice(std::string path);
	mapBtc();
	mapBtc(const mapBtc &obj);
	mapBtc &operator=(const mapBtc &obj);
	~mapBtc();
	void printMap();
	void fillMap();
	std::map<std::string, float> getMap();

	class FileNotExist : public std::exception
	{
		const char *what() const throw();
	};

	class NotPositiveNumber : public std::exception
	{
		const char *what() const throw();
	};

	class BadFormat : public std::exception
	{
		const char *what() const throw();
	};
};
bool logError(std::string str);
#endif
