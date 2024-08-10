#ifndef MAPBTC_HPP
# define MAPBTC_HPP
# include <iostream>
# include <string>
# include <map>
# include <fstream>
# include <sstream>

class mapBtc
{
	private:
		std::map<std::string, float> _map;
		void	checkKey(std::string key);
		bool	checkValue();
		bool	checkFormat(std::string key);

	public:
		mapBtc();
		mapBtc(const mapBtc &obj);
		mapBtc &operator=(const mapBtc &obj);
		~mapBtc();

		void	fillMap(std::string filePath);
		void	checkMap();

		class FileNotExist : public std::exception
		{
			const char* what() const throw();
		};

		class BadFormat : public std::exception
		{
			const char* what() const throw();
		};

};
#endif
