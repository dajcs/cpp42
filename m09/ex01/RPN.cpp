/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:31:11 by anemet            #+#    #+#             */
/*   Updated: 2025/11/12 16:13:09 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>	// std::stringstream - to parse input string
#include <cstdlib>	// std::strtol - to convert string to long

// --- Orthodox Canonical Form Implementation ---

// Default Constructor
// We don't need to do anything, the private member
// std::stack<int> _stack is automatically default constructed
RPN::RPN() {}

//Copy Constructor
RPN::RPN(const RPN& other)
{
	*this = other; // using the assignment operator to do the copying
}

// Copy Assignment Operator
RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		// std::stack has its own assignment operator, we're just calling it
		// and it will copy correctly all elements from other._stack to this->_stack
		this->_stack = other._stack;
	}
	return *this;	// return reference to make possible a = b = c chaining
}

// Destructor
// We don't need to do anything here, because the std::stack member
// will be automatically destroyed, and handles its own memory cleanup
RPN::~RPN() {}


// --- Private Helper Function ---

// Performs a single arithmetic operation
void RPN::_performOperation(char op)
{
	// Check if there are enough operands on the stack
	if (this->_stack.size() < 2)
	{
		throw std::runtime_error("Error: Not enough operands for operator");
	}

	// Pop the top two values. Note the order!
	// The second operand is on top of the stack
	int rhs = this->_stack.top();
	this->_stack.pop();
	int lhs = this->_stack.top();
	this->_stack.pop();

	// Perform the operation and push the result back onto the stack
	switch (op)
	{
		case '+':
				this->_stack.push(lhs + rhs);
				break;
		case '-':
				this->_stack.push(lhs - rhs);
				break;
		case '*':
				this->_stack.push(lhs * rhs);
				break;
		case '/':
				// Handling division by 0
				if(rhs == 0)
				{
					throw std::runtime_error("Error: Divizion by zero");
				}
				this->_stack.push(lhs / rhs);
				break;
	}
}


// --- Public Member Function Implementation ---

void RPN::evaluate(const std::string& expression)
{
	// initiating std::stringstream ss
	// this allows us to read from the string as if it were a file or STDIN
	std::stringstream ss(expression);
	std::string token;

	// This loop reads from the stringstream 'ss' one "word" (token) at a time,
	// separated by whitespace, and stores it in the 'token' variable
	while (ss >> token)
	{
		// A valid token must have exactly one character
		if (token.length() != 1)
		{
			throw std::runtime_error("Error: Invalid token");
		}

		char c = token[0];

		// Check if the character is a digit
		if (std::isdigit(c))
		{
			// if digit, convert it to an int and push it onto the stack
			this->_stack.push(c - '0');
		}
		// Check if it's one of the supported operators
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			// if it's an operator, perform the corresponding operation
			_performOperation(c);
		}
		// if neither digit nor a valid operator then it's an error
		else
		{
			throw std::runtime_error("Error: Invalid character in expressioin");
		}
	}

	// After processing all tokens, the stack must contain one value: the result
	// if this is not the case, then the expression was malformed
	if (this->_stack.size() != 1)
	{
		throw std::runtime_error("Error: Invalid expression format");
	}

	// If everything is correct print the result
	std::cout << this->_stack.top() << std::endl;

}
