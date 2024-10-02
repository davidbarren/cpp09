/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:28:13 by dbarrene          #+#    #+#             */
/*   Updated: 2024/10/02 15:06:05 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv)
{
	int num;
	m_size = argc - 1;
	m_vec.reserve(m_size);
	for (int i = 1; argv[i]; i++)
	{
		num = std::stoi(argv[i]);
		if (num < 0)
			throw std::runtime_error("Please input positive integer values");
		m_vec.push_back(num);
		m_list.push_back(num);
	}
	std::cout << "Before: ";
	for(auto &i : m_vec)
		std::cout << i << " ";
}

PmergeMe::~PmergeMe()
{
};

void PmergeMe::print_data() const
{
	for(auto &i : m_vec)
		std::cout << "vec data:" << i << std::endl;
	for(auto &i : m_list)
		std::cout << "list data:" << i << std::endl;
}
