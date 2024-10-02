/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:53:32 by dbarrene          #+#    #+#             */
/*   Updated: 2024/10/02 14:08:03 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitCoinExchange.hpp"
#include <algorithm>
#include <string>
static	bool dateValidity(std::string line, char delim)
{
	enum 
	{
		YEAR,
		MONTH,
		DAY
	};
	std::string ymd[3]; // year, month, day
	int		yr = 0, mo = 0, day = 0;
	int		index = 0;
	line = line.substr(0, line.find(delim));
	for (int i = 0; i < 3; i++)
	{
		switch(i)
		{
			case YEAR:
//				std::cout << "entered year condition" << std::endl;
				ymd[YEAR] = line;
				index = ymd[YEAR].find('-');
				ymd[YEAR] = ymd[YEAR].substr(0, ymd[YEAR].find('-'));
				yr = std::stoi(ymd[YEAR]);
				if (yr < 2009 || ymd[YEAR].length() != 4)
				{
					std::cout << "yr length check failed\n";
					return false;
				}
				
			case MONTH:
				ymd[MONTH] = line;
//				std::cout << "entered month condition" << std::endl;
				ymd[MONTH] = ymd[MONTH].substr(ymd[MONTH].find('-', index) + 1, 2);
				mo = std::stoi(ymd[MONTH]);
				if (ymd[MONTH].length() != 2 || mo <= 0 || mo > 12)
				{
					std::cout << "mo length check failed\n";
					return false;
				}
			case DAY:
				ymd[DAY] = line;
//				std::cout << "entered day condition" << std::endl;
				ymd[DAY] = ymd[DAY].substr(ymd[DAY].find_last_of('-') + 1, ymd[DAY].find(delim) - 1);
				day = std::stoi(ymd[DAY]);
				if (ymd[DAY].length() != 2 || day <= 0 || day > 31)
				{
					std::cout << "day length check failed\n";
					return false;
				}
				if ((mo < 8 && mo % 2 == 1) || (mo >= 8 && mo % 2 == 0))
				{
					if (day > 31)
						return false;
				}
				else if (mo == 2)
				{
					if (yr % 4 == 0 && day == 29)
						return true;
					else if (day > 28)
						return false;
				}
				else
					if (day > 30)
						return false;
		}
//		std::cout << "year : " << yr << std::endl;
//		std::cout << "month : " << mo << std::endl;
//		std::cout << "day : " << day << std::endl;
		return true;
	} 
	//TODO:
	//months 1, 3, 5, 7, 8, 10, 12 have 31 days
	//validate that the days are not too large for corresponding months,
	//consider leap years
	//validate that the amount after the date fits the subject
	//add valid dates + amounts to map

	return true;
}

static bool	lineValidity(std::string line, char delim)
{
	if (std::count(line.begin(), line.end(), delim) != 1)
		return false;
	if (std::count(line.begin(), line.end(), '-') != 2)
		return false;
	if (line.find('-') != 4 && line.find_last_of('-' != 7))
			return false;
	if (line.find(delim) == SIZE_MAX)
			return false;
	return true;

}
BitCoinExchange::BitCoinExchange(std::string wallet)
{
	parseExchange();
//	printMap();
	parseWallet(wallet);
};
BitCoinExchange::~BitCoinExchange()
{
};

void BitCoinExchange::parseExchange()
{
	std::ifstream input("testdata.csv");
	if (!input.is_open())
		throw ::std::runtime_error("failed to open data file");
	std::string line;
	std::getline(input, line);

	while (std::getline(input, line))
	{
		if (!lineValidity(line, ','))
			throw std::runtime_error("bad line");
		if (!dateValidity(line, ','))
		{
			std::cout << "caught bad date" << line << std::endl;
			throw std::runtime_error("bad date");
		}
		treatLine(line);
	}

};

static bool	is_contiguous(std::string val)
{
	bool has_decimal = false;
	if (val.back() == '.')
		return false;
	for (std::string::iterator iter = val.begin(); iter != val.end(); iter++)
	{
		if (!has_decimal && *iter == '.')
				has_decimal = true;
		else if (!std::isdigit(*iter))
			return false;
	}
	return true;
}

void BitCoinExchange::treatLine(std::string &line)
{
	std::string value;
	float rate;
	value = line.substr(line.find(',') + 1);
	line = line.substr(0, line.find(','));
//	std::cout << "line is: " << line << std::endl;
//	std::cout << "value is: " << value << "\n";
	if (!is_contiguous(value))
		throw std::runtime_error("invalid csv file");
	rate = std::stof(value);
	m_rates.insert(std::map<std::string, float>::value_type(line,rate));
};

void	BitCoinExchange::printMap() const
{
	for(auto &i : m_rates)
	{
		std::cout << "key : " << i.first << "\n";
		std::cout << "value : " << i.second << "\n";
	}
}

void	BitCoinExchange::parseWallet(std::string wallet)
{
	std::ifstream infile(wallet);
	std::string line;
	std::string date;
	std::string value;
	float valnum = 0;
	if (!infile.is_open())
		throw std::runtime_error("failed to open wallet");
	std::getline(infile,line);
	while (std::getline(infile, line))
	{
//		line.replace(line.find(" | "), 3, "|");
//		std::cout << "linestatus: " << line << std::endl;
		date = line.substr(0, line.find(' '));
		value = line.substr(line.find_last_of(' ') + 1);
		if (!is_contiguous(value))
		{
			std::cerr << "Error: not a valid number.\n";
			continue ;
		}
		valnum = std::stof(value);
		if (valnum < 0)
		{
			std::cerr << "Error: not a positive number.\n";
			continue ;
		}
		if (valnum > 1000)
		{
			std::cerr << "Error: too large a number.\n";
			continue ;
		}
		if (!lineValidity(line, '|'))
		{
			std::cerr << "Error: incorrect format => " << line << "\n";
			continue ;
		}
		if (!dateValidity(line.substr(0, 10), '|'))
		{
			std::cerr << "value of line: " << line << std::endl;
			std::cerr << "Error: incorrect date input => " << date << "\n";
			continue ;
		}
		printValue(date, valnum);
	}
}

void	BitCoinExchange::printValue(std::string key, float num) const
{
	float result;
	try
	{
		for (auto &iter : m_rates)
		{
			if (key >= iter.first)
			{
				result = iter.second * num;
			}
		}
	}
	catch(std::exception &e)
	{
		std::cout << "HUH?" << std::endl;
	}
	std::cout << key << " => " << num << " = " << result << std::endl;
}
