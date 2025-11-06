/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:16:11 by anemet            #+#    #+#             */
/*   Updated: 2025/11/06 15:58:50 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

// A simple class to test the Array with a complex type
class Awesome
{
	private:
		int _n;
	public:
		Awesome(int n = 0) : _n(n) {}
		int get() const {return _n;}
};
// Overload the << operator to allow printing Awesome objects easily.
std::ostream& operator<<(std::ostream& os, const Awesome& a)
{
	os << a.get();
	return os;
}


void testIntArray()
{
	std::cout << "\n--- Testing Array<int> ---" << std::endl;

	// Test default constructor
	Array<int> empty;
	std::cout << "Size of default-constructed array: " << empty.size() << std::endl;

	// Test constructor with size
	unsigned int n = 5;
	Array<int> numbers(n);
	std::cout << "Size of array constructed with size " << n << ": " << numbers.size() << std::endl;

	// Test element access and modification
	for (unsigned int i = 0; i < numbers.size(); ++i)
	{
		numbers[i] = i * 10;
	}

	std::cout << "Initialized array: ";
	for (unsigned int i = 0; i < numbers.size(); ++i)
	{
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;

	// Test copy constructor
	Array<int> copy(numbers);
	std::cout << "Copied array: ";
	for (unsigned int i = 0; i < copy.size(); ++i)
	{
		std::cout << copy[i] << " ";
	}
	std::cout << std::endl;

	// Modify the original and check if the copy is affected
	numbers[0] = 999;
	std::cout << "Original array[0] after modification: " << numbers[0] << std::endl;
	std::cout << "Copied array[0] after original was modified: " << copy[0] << " (should be 0)" << std::endl;

}

void testStringArray()
{
	std::cout << "\n--- Testing Array<std::string> ---" << std::endl;
	Array<std::string> words(3);
	words[0] = "Hello";
	words[1] = "World";
	words[2] = "!";

	std::cout << "String array: ";
	for (unsigned int i = 0; i < words.size(); ++i)
	{
		std::cout << words[i] << " ";
	}
	std::cout << std::endl;
}

void testComplexTypeArray()
{
	std::cout << "\n--- Testing Array<Awesome> ---" << std::endl;
	Array<Awesome> awesomeArray(4);
	for (unsigned int i = 0; i < awesomeArray.size(); ++i)
	{
		awesomeArray[i] = Awesome(i + 1);
	}
	std::cout << "Awesome array: ";
	for (unsigned int i = 0; i < awesomeArray.size(); ++i)
	{
		std::cout << awesomeArray[i] << " ";
	}
	std::cout << std::endl;
}

void testExceptions()
{
	std::cout << "\n--- Testing Exceptions ---" << std::endl;
	Array<int> arr(10);
	try
	{
		std::cout << "Accessing a valid index (arr[5]): " << arr[5] << std::endl;
		std::cout << "Accessing an invalid index (arr[10])..." << std::endl;
		arr[10] = 100; // This will throw an exceptions
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << '\n';
	}

	try
	{
		std::cout << "Accessing an invalid index (arr[-1])..." << std::endl;
		arr[-1] = 42; // This will be out of bounds also (very large unsigned int)
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << '\n';
	}


}



int main()
{
	testIntArray();
	testStringArray();
	testComplexTypeArray();
	testExceptions();

	return 0;
}
