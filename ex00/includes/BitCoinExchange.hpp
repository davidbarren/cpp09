/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:46:06 by dbarrene          #+#    #+#             */
/*   Updated: 2024/10/02 13:39:15 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <map>
#include <string>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <iostream>
class BitCoinExchange
{
	std::map<std::string, float> m_rates;
	public:
		BitCoinExchange(std::string wallet);
		~BitCoinExchange();
		BitCoinExchange(const BitCoinExchange& other);
		BitCoinExchange& operator=(const BitCoinExchange& other);
		void parseExchange();
		void treatLine(std::string &line);
		void printMap() const;
		void parseWallet(std::string wallet);
		void printValue(std::string key, float num) const;
};

#endif
