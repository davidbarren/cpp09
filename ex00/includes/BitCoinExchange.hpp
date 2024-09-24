/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:46:06 by dbarrene          #+#    #+#             */
/*   Updated: 2024/09/24 15:12:55 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
class BitCoinExchange
{
	std::map<std::string,std::string> map;
	public:
		BitCoinExchange();
		~BitCoinExchange();
		BitCoinExchange(const BitCoinExchange& other);
		BitCoinExchange& operator=(const BitCoinExchange& other);
		void calculateExchange(std::string arg);
};

#endif
