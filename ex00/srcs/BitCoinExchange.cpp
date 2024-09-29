/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:53:32 by dbarrene          #+#    #+#             */
/*   Updated: 2024/09/30 00:16:56 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitCoinExchange.hpp"

static	bool dateValidity(std::string line)
{
	enum 
	{
		YEAR,
		MONTH,
		DAY
	};
	std::string ymd[3]; // year, month, day
	int		yr, mo, day;
	int		index = 0;
	line = line.substr(0, line.find(','));
	for (int i = 0; i < 3; i++)
	{
		switch(i)
		{
			case YEAR:
				ymd[YEAR] = line;
				index = ymd[YEAR].find('-');
				ymd[YEAR] = ymd[YEAR].substr(0, ymd[YEAR].find('-'));
				yr = std::stoi(ymd[YEAR]);
				if (yr < 2009 || ymd[YEAR].length() != 4)
					return false;
				std::cout << "year: " << ymd[YEAR] << std::endl;
				break;
			case MONTH:
				ymd[MONTH] = line;
				ymd[MONTH] = ymd[MONTH].substr(ymd[MONTH].find('-', index) + 1, 2);
				std::cout << "month: " << ymd[MONTH] << "\n";
				mo = std::stoi(ymd[MONTH]);
				if (ymd[MONTH].length() != 2 || mo <= 0 || mo > 12)
					return false;
				break;
			case DAY:
				ymd[DAY] = line;
				ymd[DAY] = ymd[DAY].substr(ymd[DAY].find_last_of('-') + 1, ymd[DAY].find(',') - 1);
				std::cout << "day: " << ymd[DAY] << "\n";
				day = std::stoi(ymd[DAY]);
				if (ymd[DAY].length() != 2 || day <= 0 || day > 31)
					return false;
				if ((mo < 8 && mo % 2 == 1) || (mo >= 8 && !mo % 2))
				{
					if (day > 31)
						return false;
				}
				else if (mo == 2)
				{
					if (!yr % 4 && day > 29)
						return false;
					else if (day > 28)
						return false;
				}
				else
					if (day > 30)
						return false;
				break;
		}
		std::cout << "date is indeed valid \n";
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

static bool	lineValidity(std::string line)
{
	if (line.find('-') != 4 && line.find_last_of('-' != 7))
			return false;
	if (line.find(',') == SIZE_MAX)
			return false;
	return true;

}
BitCoinExchange::BitCoinExchange()
{
	parseExchange();
};
BitCoinExchange::~BitCoinExchange()
{
};

void BitCoinExchange::parseExchange()
{
	std::ifstream input("data.csv");
	std::string line;
	std::getline(input, line);

	while (std::getline(input, line))
	{
		std::cout << line << std::endl;
		if (!lineValidity(line))
			throw std::runtime_error("bad line");
		if (!dateValidity(line))
			throw std::runtime_error("bad line");
	}

};

