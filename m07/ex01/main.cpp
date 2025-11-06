/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:37:57 by anemet            #+#    #+#             */
/*   Updated: 2025/11/06 14:09:10 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

// ===== Test Functions =====

// 1. A function template to print any type of element.
// 		Passing an instantiated function template to 'iter'
//		It takes a const reference because it only read the element
template <typename T>
void printElement(const T& element)
{
	std::cout << element << std::endl;
}

// 2. A function to increment an integer
//		This takes a non-const reference (it modifies the element)
void incrementInt(int& n)
{
	n++;
}

// 3. A function to convert a character to uppercase
// 		This also takes a non-const reference to modify the element
void toUpperCase(char& c)
{
	if (c >= 'a' && c <= 'z')
	{
		c = c - 32;
	}
}


// ===== Main program for testing =====

int main()
{
	// --- Test 1: Integer array (modification) ---
	std::cout << "--- Testing with integer array ---" << std::endl;
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intArrayLength = sizeof(intArray) / sizeof(int);

	std::cout << "Original array:" << std::endl;
	// Here, iter is instantiated with T = int.
	// printElement<int> is the specific version of our print function
	iter(intArray, intArrayLength, printElement<int>);

	std::cout << "\nIncrementing each element..." << std::endl;
	iter(intArray, intArrayLength, incrementInt);

	std::cout << "Array after incrementing:" << std::endl;
	iter(intArray, intArrayLength, printElement<int>);
	std::cout << std::endl;


	// --- Test 2: Character array (modification) ---
	std::cout << "--- Testing with char array ---" << std::endl;
	char charArray[] = {'a', 'b', 'c', 'd', 'e'};
	size_t charArrayLength = sizeof(charArray) / sizeof(char);

	std::cout << "Original array:" << std::endl;
	iter(charArray, charArrayLength, printElement<char>);

	std::cout << "\nConverting to uppercase..." << std::endl;
	iter(charArray, charArrayLength, toUpperCase);

	std::cout << "Array after conversion:" << std::endl;
	iter(charArray, charArrayLength, printElement<char>);
	std::cout << std::endl;


	// --- Test 3: Const string array (read-only) ---
	std::cout << "--- Testing with const string array ---" << std::endl;
	const std::string stringArray[] = {"Hello", "World", "42", "School"};
	size_t stringArrayLength = sizeof(stringArray) / sizeof(std::string);

	std::cout << "Printing a const array:" << std::endl;
	iter(stringArray, stringArrayLength, printElement<std::string>);
	std::cout << std::endl;

	return 0;
}
