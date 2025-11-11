/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:53:52 by anemet            #+#    #+#             */
/*   Updated: 2025/11/11 14:03:58 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

void testSubject()
{
	std::cout << "--- Subject's Main Test ---" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	// .top() returns a reference to the top element (17)
	std::cout << "Top element is: " << mstack.top() << std::endl;

	// .pop() removes the top element (17)
	mstack.pop();

	// .size() returns the number of elements
	std::cout << "Size after pop: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	// Get iterators for the stack
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it; // Move iterator to the second element
	--it; // Move it back to the first element

	std::cout << "Iterating through MutantStack:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl; // dereference it to get the value -> *it
		++it; // move to the next element
	}

	// Test copy constructor and assignment by creating a std::stack from our MutantStack
	std::stack<int> s(mstack);


	// Subject's tests with std::list for comparison
	std::cout << "\n--- Subject's Test with std::list for comparison ---" << std::endl;

	// The same operations with std::list
	std::list<int> mlist;
	mlist.push_back(5);
	mlist.push_back(17);
	std::cout << "Back element is: " << mlist.back() << std::endl;
	mlist.pop_back();
	std::cout << "Size after pop: " << mlist.size() << std::endl;
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	mlist.push_back(0);
	std::list<int>::iterator itl = mlist.begin();
	std::list<int>::iterator itel = mlist.end();
	++itl;
	--itl;
	std::cout << "Iterating through std::list:" << std::endl;
	while (itl != itel)
	{
		std::cout << *itl << std::endl;
		++itl;
	}
}

void additionalTests()
{
	std::cout << "\n--- Additional Tests ---" << std::endl;

	// Test with a different type
	MutantStack<std::string> stringStack;
	stringStack.push("Hello");
	stringStack.push("World");
	stringStack.push("42");

	std::cout << "Top of string stack: " << stringStack.top() << std::endl;

	// Test copy constructor and assignment operator
	MutantStack<std::string> copiedStack(stringStack); // Copy constructor
	MutantStack<std::string> assignedStack;
	assignedStack = copiedStack; // Assignment operator

	std::cout << "\nIterating through assigned string stack:" << std::endl;
	for (MutantStack<std::string>::iterator it = assignedStack.begin();
												it != assignedStack.end(); ++it)
	{
		std::cout << *it << std::endl;
	}

	// Test reverse iterators
	std::cout << "\nIterating backwards through assigned string stack:" << std::endl;
	for (MutantStack<std::string>::reverse_iterator rit = assignedStack.rbegin();
												rit != assignedStack.rend(); ++rit)
	{
		std::cout << *rit << std::endl;
	}

	// Test empty stack
	MutantStack<int> emptyStack;
	std::cout << "\n--- emptyStack Tests ---" << std::endl;
	std::cout << "Is the new stack empty? " << (emptyStack.empty() ? "Yes" : "No") << std::endl;
	std::cout << "Size of empty stack: " << emptyStack.size() << std::endl;
	// The begin() and end() iterators on an empty container should be equal
	if (emptyStack.begin() == emptyStack.end())
	{
		std::cout << "Iterators .begin() and .end() are equal on an empty stack" << std::endl;
	}
}

int main()
{
	testSubject();
	additionalTests();

	return 0;
}
