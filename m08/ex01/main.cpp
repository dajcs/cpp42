/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:10:26 by anemet            #+#    #+#             */
/*   Updated: 2025/11/07 15:53:39 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>	// srand(), rand()
#include <ctime>	// time()

void subjectTest()
{
	std::cout << "--- Subject Test ---" << std::endl;
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	sp.printNumbers();

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

void exceptionTests()
{
	std::cout << "--- Exception Tests ---" << std::endl;
	Span sp_full(3);
	sp_full.addNumber(1);
	sp_full.addNumber(2);
	sp_full.addNumber(3);
	sp_full.printNumbers();
	try
	{
		std::cout << "Trying to add a 4th number to a full Span[3/3]..." << std::endl;
		sp_full.addNumber(4);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught expected exception: " << e.what() << '\n';
	}
	std::cout << std::endl;


	Span sp_one(5);
	sp_one.addNumber(42);
	sp_one.printNumbers();
	try
	{
		std::cout << "Trying to find shortest span with one number..." << std::endl;
		sp_one.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught expected exception: " << e.what() << '\n';
	}
	std::cout << std::endl;
	try
	{
		std::cout << "Trying to find longest span with one number..." << std::endl;
		sp_one.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught expected exception: " << e.what() << '\n';
	}
	std::cout << std::endl;
}

void largeScaleTest()
{
	std::cout << "--- Large Scale Test (1,000,000 numbers) ---" << std::endl;
	const unsigned int num_elements = 1000000;
	Span sp_large(num_elements);

	std::vector<int> large_vector;
	large_vector.reserve(num_elements);
	std::srand(std::time(0));
	for (unsigned int i = 0; i < num_elements; ++i)
	{
		large_vector.push_back(rand());
	}
	try
	{
		sp_large.addNumber(large_vector.begin(), large_vector.end());
		std::cout << "Successfully added 1,000,000 numbers." << std::endl;
		// print check
		sp_large.printNumbers();
		std::cout << "Shortest span: " << sp_large.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp_large.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught unexpected exception: " << e.what() << '\n';
	}

}


int main()
{
	subjectTest();
	exceptionTests();
	largeScaleTest();
}
