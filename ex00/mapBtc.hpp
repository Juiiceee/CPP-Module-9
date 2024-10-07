#ifndef MAPBTC_HPP
#define MAPBTC_HPP
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>

class mapBtc
{
private:
	std::map<std::string, float> _map;
	bool checkValue();
	bool checkYears(std::string key);
	bool checkMonths(std::string key);
	bool checkDays(std::string key);
	bool checkDates(int years, int months, int days);

public:
	bool checkFormat(std::string key);
	void checkKey(std::string key);
	mapBtc();
	mapBtc(const mapBtc& obj);
	mapBtc& operator=(const mapBtc& obj);
	~mapBtc();

	void fillMap();
	void checkMap();

	class FileNotExist : public std::exception
	{
		const char* what() const throw();
	};

	class NotPositiveNumber : public std::exception
	{
		const char* what() const throw();
	};

	class BadFormat : public std::exception
	{
		const char* what() const throw();
	};
};
#endif
