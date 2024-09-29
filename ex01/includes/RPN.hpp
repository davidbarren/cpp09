/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 23:10:17 by dbarrene          #+#    #+#             */
/*   Updated: 2024/09/27 15:43:21 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef RPN_HPP
#define RPN_HPP
#include <stack>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <chrono>
enum t_operators
{
	PLUS,
	MINUS,
	MULTIPLICATION,
	DIVISION,
};

class RPN
{
	private:
		std::stack<int64_t>	m_stack;
		void parse_expr(std::string expr);
	public:
		RPN(std::string expr);
		~RPN();
		RPN(const RPN& other) = delete;
		RPN& operator=(const RPN& other) = delete;
};
#endif
