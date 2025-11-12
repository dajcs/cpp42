/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:16:19 by anemet            #+#    #+#             */
/*   Updated: 2025/11/12 11:29:52 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>	// std::exception
# include <string>		// std::string
# include <stack>		// std::stack

class RPN
{
	public:
		// --- Orthodox Canonical Form ---

		// 1. Default Constructor:
		RPN();
		// 2. Copy Constructor
		RPN(const RPN& other);
		// 3. Copy Assignment Operator:
		RPN& operator=(const RPN& other);
		// 4. Destructor
		~RPN();


		// --- Public Member Function ---

		// The main function to evaluate the RPN expression
		// It takes the expression as a constant string reference to avoid making a copy
		void evaluate(const std::string& expression);


	private:
		// --- Private Member Variable ---

		// A stack of integers. This is the core of the RPN calculator
		// std::stack is a "container adapter". By default it uses std::deque
		// (a double-ended queue) internally to store its elements.
		// It's private because only the class methods will iteract with it
		std::stack<int> _stack;

		// Private Member Functions (Helpers) ---

		// Helper function to perform the actual calculation
		void _performOperation(char op);
};

#endif
