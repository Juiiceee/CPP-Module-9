#include "mapBtc.hpp"

mapBtc::mapBtc()
{
	std::cout << "mapBtc default constructor called\n";
}

mapBtc::mapBtc(const mapBtc &obj)
{
	std::cout << "Copy constructor called\n";
	*this = obj;
	return ;
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

void	mapBtc::fillMap(std::string filePath)
{
	std::string tmp;
	std::string key;
	float value;
	std::ifstream file(filePath.c_str());
	if (!file.good())
		throw FileNotExist();
	std::getline(file, tmp);
	while (std::getline(file, tmp))
	{
		key = tmp.substr(0, tmp.find(' | '));
		std::stringstream svalue(tmp.substr(tmp.find(' | ') + 1, tmp.size()));
		svalue >> value;
		_map.insert(std::make_pair(key, value));
	}
}

void	mapBtc::checkMap()
{
	for (std::map<std::string, float>::iterator it = _map.begin(); it != _map.end(); it++)
	{
		if (!checkFormat(it->first))
			continue;
		if ()
	}
}

void	mapBtc::checkKey(std::string key)
{

}

bool logError(std::string str)
{
	std::cout << "Error: " << str << std::endl;
	return (false);
}

bool	mapBtc::checkFormat(std::string key)
{
	int	i = 0;
	int	j = 0;

	while (isdigit(key[i + j]))
	i++;
	if (i != 4 || key[j + i++] != '-')
		return (logError("bad input => " + key));
	j += i;
	i = 0;
	while (isdigit(key[i + j]))
		i++;
	if (i != 2 || key[j + i++] != '-')
		return (logError("bad input => " + key));
	j += i;
	i = 0;
	while (isdigit(key[i + j]))
		i++;
	if (i != 2 || key.size() != j + i)
		return (logError("bad input => " + key));
	return (true);
}

const char* mapBtc::FileNotExist::what() const throw()
{
	return ("File Not Exist\n");
}

const char* mapBtc::BadFormat::what() const throw()
{
	return ("Bad Format\n");
}

