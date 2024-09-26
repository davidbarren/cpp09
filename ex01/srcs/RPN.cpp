/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 23:16:35 by dbarrene          #+#    #+#             */
/*   Updated: 2024/09/27 01:04:00 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static void calc_expr(std::stack<int32_t> &st, int32_t (*f)(int32_t, int32_t))
{
	if (st.size() < 2)
		throw std::runtime_error("invalid expression in RPN");
	int32_t operand1 = st.top();
	st.pop();
	int32_t operand2 = st.top();
	st.pop();
	st.push(f(operand2, operand1));
}

static int32_t add(int32_t a, int32_t b)
{
	return a + b;
}


static int32_t subtract(int32_t a, int32_t b)
{
	return a - b;
}

static int32_t multiply(int32_t a, int32_t b)
{
	return a * b;
}

static int32_t divide(int32_t a, int32_t b)
{
	if (!b)
		throw std::runtime_error("Division by zero attempted");
	return a / b;
}
RPN::RPN(std::string expr)
{
	parse_expr(expr);
};

RPN::~RPN(){
};

static int	is_operator(int c)
{
	switch (c)
	{
		case '+':
			return PLUS;
		case '-':
			return MINUS;
		case '*':
			return MULTIPLICATION;
		case '/':
			return DIVISION;
	}
	return -1;
}

void	RPN::parse_expr(std::string expr)
{
	int32_t (*fun_calc[4])(int32_t, int32_t) = {&add, &subtract, &multiply, &divide};
	if (is_operator(expr.back()) == -1)
		throw std::runtime_error("incorrect use of reverse polish notation");
	for (std::string::iterator i = expr.begin(); i != expr.end(); i++)
	{
		if (std::isdigit(*i) && *(i + 1) == ' ')
			m_stack.push(static_cast<int>(*i) - '0');
		else if (is_operator(*i) != -1)
			calc_expr(m_stack, fun_calc[is_operator(*i)]);
		else if (*i != ' ')
			throw std::runtime_error("please input only positive integers ranging from 0 - 9");
	};
	if (m_stack.size() > 1)
		throw std::runtime_error("incorrect use of reverse polish notation");
	std::cout << "result: " << m_stack.top() << std::endl;
};
