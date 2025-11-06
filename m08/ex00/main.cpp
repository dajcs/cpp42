/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 20:24:11 by anemet            #+#    #+#             */
/*   Updated: 2025/11/06 20:56:37 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

// Helper function to print the contents of a container
// This is also a template so it can work with any container type we test
template <typename T>
void printContainer(const T& container, const std::string& name)
{
	std::cout << name << " contains: ";
	// We must use a const_iterator because the container is passed as a
	// constant referece, meaning we promis not to change it
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}


int main()
{
	// --- Test with std::vector ---
	std::cout << "--- Testing with std::vector ---" << std::endl;

	std::vector<int> numbers_vector;
	numbers_vector.push_back(10);
	numbers_vector.push_back(25);
	numbers_vector.push_back(-5);
	numbers_vector.push_back(42);
	numbers_vector.push_back(100);
	printContainer(numbers_vector, "numbers_vector");

	// TC1: Value is present
	try
	{
		int value_to_find = 42;
		std::cout << "Searching for " << value_to_find << "... ";
		// calling easyfind insid a 'try' block because it might throw
		std::vector<int>::iterator result = easyfind(numbers_vector, value_to_find);
		// If no exception is thrown, the line below will execute
		// result has the iterator, and we'll dereference it
		std::cout << "Found value: " << *result << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	// TC2: Value is not present
	try
	{
		int value_to_find = 999;
		std::cout << "Searching for " << value_to_find << "... ";
		easyfind(numbers_vector, value_to_find);
		std::cout << "This line should not be printed" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught expected exception: " << e.what() << '\n';
	}

	std::cout << std::endl;

	// --- Test with std::list ---
	std::cout << "--- Testing with std::list ---" << std::endl;

	std::list<int> numbers_list;
	numbers_list.push_back(1);
	numbers_list.push_back(2);
	numbers_list.push_back(3);
	printContainer(numbers_list, "numbers_list");

	// TC3: Value is present in the list
	try
	{
		int value_to_find = 1;
		std::cout << "Searching for " << value_to_find << "... ";
		std::list<int>::iterator result = easyfind(numbers_list, value_to_find);
		std::cout << "Found value: " << *result << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	// TC4: Value is not present in the list
	try
	{
		int value_to_find = 5;
		std::cout << "Searching for " << value_to_find << "... ";
		easyfind(numbers_list, value_to_find);
		std::cout << "This line should not be printed." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught expected exception: " << e.what() << '\n';
	}

	return 0;
}
