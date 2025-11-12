/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:53:52 by anemet            #+#    #+#             */
/*   Updated: 2025/11/12 10:24:00 by anemet           ###   ########.fr       */
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

// deque -> list container
void testWithListContainer()
{
	std::cout << "\n--- Testing with std::list as the underlying container ---" << std::endl;

	// We explicitly provide the second template argument
	// reminder when we specified the first template argument only:
	// 											MutantStack<int> mstack;
	//											MutantStack<std::string> stringStack;
	MutantStack<int, std::list<int> > list_based_stack;

	// The stack interface works the same
	list_based_stack.push(0);
	list_based_stack.push(10);
	list_based_stack.push(100);
	list_based_stack.push(200);
	list_based_stack.push(300);

	std::cout << "Size: " << list_based_stack.size() << std::endl;	// expecting 5
	std::cout << "Top: " << list_based_stack.top() << std::endl; 	// expecting 300

	list_based_stack.pop();

	std::cout << "After pop, Top: " << list_based_stack.top() << std::endl; // expected 200

	// the iterators still work because std::list has them
	std::cout << "Iterating through the list-based MutantStack:" << std::endl;

	// We must use the specific iterator type for this instantiation of the stack
	MutantStack<int, std::list<int> >::iterator it = list_based_stack.begin();
	MutantStack<int, std::list<int> >::iterator ite = list_based_stack.end();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

int main()
{
	testSubject();
	additionalTests();
	testWithListContainer();

	return 0;
}
