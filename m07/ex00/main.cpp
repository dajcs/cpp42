/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:03:08 by anemet            #+#    #+#             */
/*   Updated: 2025/11/06 12:51:41 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>
#include <string>

// A simple test function to demonstrate the functionality with a given title
void run_tests(const std::string& title)
{
	std::cout << "\n--- " << title << " ---" << std::endl;

	if (title == "Provided Tests")
	{
		int a = 2;
		int b = 3;

		std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
		::swap(a, b); // The :: is the global scope resolution operator
		std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";

		std::cout << "\nBefore swap: c = " << c << ", d = " << d << std::endl;
		::swap(c, d);
		std::cout << "After swap: c = " << c << ", d = " << d << std::endl;
		std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
		std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
	}
	else if (title == "Float Tests")
	{
		float e = 42.42f;
		float f = 21.21f;

		std::cout << "Before swap: e = " << e << ", f = " << f << std::endl;
		::swap(e,f);
		std::cout << "After swap: e = " << e << ", f = " << f << std::endl;
		std::cout << "min(e, f) = " << ::min(e, f) << std::endl;
		std::cout << "max(e, f) = " << ::max(e, f) << std::endl;
	}
	else if (title == "Char Tests")
	{
		char g = 'a';
		char h = 'z';

		std::cout << "Before swap: g = " << g << ", h = " << h << std::endl;
		::swap(g, h);
		std::cout << "After swap: g = " << g << ", h = " << h << std::endl;
		std::cout << "min(g, h) = " << ::min(g, h) << std::endl;
		std::cout << "max(g, h) = " << ::max(g, h) << std::endl;
	}
	else if (title == "Edge Case: Equal Values")
	{
		int i = 5;
		int j = 5;

		std::cout << "Before swap: i = " << i << ", j = " << j << std::endl;
		std::cout << "Before swap: &i = " << &i << ", &j = " << &j << std::endl;
		std::cout << "After swap: i = " << i << ", j = " << j << std::endl;
		std::cout << "After swap: &i = " << &i << ", &j = " << &j << std::endl;
		std::cout << "min(i, j) = " << ::min(i, j) << std::endl;
		std::cout << "&(min(i, j)) = " << &(::min(i, j)) << std::endl;
		std::cout << "max(i, j) = " << ::max(i, j) << std::endl;
		std::cout << "&(max(i, j)) = " << &(::max(i, j)) << std::endl;
	}
}

int main()
{
	run_tests("Provided Tests");
	run_tests("Float Tests");
	run_tests("Char Tests");
	run_tests("Edge Case: Equal Values");
}
