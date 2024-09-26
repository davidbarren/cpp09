/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:44:13 by dbarrene          #+#    #+#             */
/*   Updated: 2024/09/26 23:52:23 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Please provide an expression in reverse polish notation" << std::endl;
		std::cout << "Usage: " << std::endl << "./RPN \"2 2 +\"" << std::endl;
		std::cout << "Expected result: 4" << std::endl;
		std::cout << "Keep in mind this calculator only accepts positive integers ranging from 0-9" << std::endl;
		return 1;
	}
	try
	{
		std::string expression = argv[1];
		RPN calc(expression);
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
}
