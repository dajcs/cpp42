/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:35:04 by anemet            #+#    #+#             */
/*   Updated: 2025/11/05 21:54:13 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>		// std::cout
#include <cstdlib>		// std::rand(), std::srand()
#include <ctime>		// std::time()
#include <exception>	// std::exception (try/catch block)

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

/* generate()
	Randomly instantiates an object of type A, B, or C and returns it
	as a pointer to the base class Base.
*/
Base* generate(void)
{
	// Generate a random number between 0 and 2
	int random_choice = std::rand() % 3;

	if (random_choice == 0)
	{
		std::cout << "Generated type: A" << std::endl;
		return new A();
	}
	else if (random_choice == 1)
	{
		std::cout << "Generated type: B" << std::endl;
		return new B();
	}
	else // if (random_choice == 2)
	{
		std::cout << "Generated type: C" << std::endl;
		return new C();
	}
}

/* identify(Base* p)
	Identifies the actual type of the object pointed to by p.
	It takes a pointer to Base as a parameter
	How it works:
	- dynamic_cast<T*>(p) tries to convert the base pointer 'p' to
		derived pointer of type T*
	- if the object that 'p' points to is actually of type T
		(or a class derived from T), the cast succeeds and returns a valid pointer
	- if the object is of a different type, the cast fails and returns NULL.
*/
void identify(Base* p)
{
	std::cout << "identify(base* p): Actual type is -> ";
	// Try to cast to A*. If it's not NULL, then the object is of type A
	if (dynamic_cast<A*>(p))
	{
		std::cout << "A" << std::endl;
	}
	// if the first cast failed, try to cast to B*
	else if (dynamic_cast<B*>(p))
	{
		std::cout << "B" << std::endl;
	}
	// if both failed, try to cast to C*
	else if (dynamic_cast<C*>(p))
	{
		std::cout << "C" << std::endl;
	}
	else
	{
		std::cout << "Unknown type" << std::endl;
	}
}

/* identify(Base& p)
	Identifies the actual type of the object referred to by p.
	It takes a reference to Base as a parameter.
		(Using  a pointer in this function is forbidden)
	How it works:
	- dynamic_cast<T&>(p) tries to convert the base reference 'p'
		to a derived reference of type T&
	- if the object that 'p' refers to is actually of type T, the cast succeeds
	- if the object is of different type, the cast fails and throws a std::bad_cast exception
*/
void identify(Base& p)
{
	std::cout << "identify(Base& p): Actual type is -> ";

	// First, try to cast to type A&
	try
	{
		// If this cast succeeds, the object is of type A
		// We declare a temporary variable to make the cast happen
		// The 'unused' attribute is to silence compiler warning
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return; // Type found, so we exit the function
	}
	catch(const std::exception& e)
	{
		// If it throws, the cast failed.
		// We don nothing and proceed to the next try block
		// std::cerr << e.what() << '\n';
	}
	// A& cast failed, let's try B&
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch(const std::exception& e)
	{
		// std::cerr << e.what() << '\n';
	}
	// If both failed, try to cast to C&
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch(const std::exception& e)
	{
		// Cast failed
	}

}


int main()
{
	// Seed the random number generator
	// std::srand() should only be called once at the beginning of the program
	// Using std::time(NULL) provides a different seed for each run,
	// making the sequence of random numbers different each time
	std::srand(std::time(NULL));

	Base* ptr = NULL;

	// --- Test 1 ---
	std::cout << "--- Test 1 ---" << std::endl;
	ptr = generate();		// create a random object
	identify(ptr);			// identify via pointer
	identify(*ptr);			// identify via reference (dereference the pointer)
	delete ptr;				// free the allocated memory to prevent leaks
	std::cout << std::endl;

	// --- Test 2 ---
	std::cout << "--- Test 2 ---" << std::endl;
	ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete ptr;
	std::cout << std::endl;

	// --- Test 3 ---
	std::cout << "--- Test 3 ---" << std::endl;
	ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete ptr;

	return 0;
}
