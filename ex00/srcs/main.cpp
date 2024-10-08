/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:44:13 by dbarrene          #+#    #+#             */
/*   Updated: 2024/09/30 14:55:11 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitCoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Please provide an input file" << std::endl;
		return 1;
	}
	try {
		std::cout << argv[1] << std::endl;
		BitCoinExchange mybtc(argv[1]);
	}
	catch(std::exception &e)
	{
		std::cout << "caught exception: " << e.what() << "\n";
		return 69;
	}


}
