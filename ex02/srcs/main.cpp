/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:23:39 by dbarrene          #+#    #+#             */
/*   Updated: 2024/10/02 14:38:29 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc <= 2)
	{
		std::cerr << "Please input a valid sequence of integers to be sorted\n";
		return 1;
	}
	try
	{
		PmergeMe merger(argc, argv);
	}
	catch (std::exception &e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
}
