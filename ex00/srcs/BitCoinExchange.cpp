/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:53:32 by dbarrene          #+#    #+#             */
/*   Updated: 2024/09/24 15:12:54 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitCoinExchange.hpp"

BitCoinExchange::BitCoinExchange()
{
};
BitCoinExchange::~BitCoinExchange()
{
};

void BitCoinExchange::calculateExchange(std::string arg)
{
	std::ifstream input;
	input.open("data.csv");
	if (!input.is_open())
		std::cout << "error opening data file, throw exception or smth" << std::endl;

};
