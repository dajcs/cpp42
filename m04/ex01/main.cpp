/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 21:27:58 by anemet            #+#    #+#             */
/*   Updated: 2025/10/31 09:50:17 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

void run_subject_tests()
{
	std::cout << "\n--- Running Subject Main Test ---" << std::endl;
	const int array_size = 4; // small array for concise output
	Animal* animals[array_size];

	// Fill the first half with Dogs
	for (int i = 0; i < array_size / 2; ++i)
	{
		std::cout << "\n--- Creating Dog " << i << " ---" << std::endl;
		animals[i] = new Dog();
	}

	// Fill the seconds half with Cats
	for (int i = array_size / 2; i < array_size; ++i)
	{
		std::cout << "\n--- Creating Cat " << i << " ---" << std::endl;
		animals[i] = new Cat();
	}

	// Deleting Animals
	std::cout << "\n--- Deleting all animals ---" << std::endl;
	// Loop over the array and delete every Animal
	for (int i = 0; i < array_size; ++i)
	{
		std::cout << "\n--- Deleting Animal " << i << " ---" << std::endl;
		// Because Animal's destructor is virtual, this will call the correct
		// derived destructor (Dog or Cat), which deletes its brain, and then
		// the base Animal destructor is called. No leaks!
		delete animals[i];
	}
}

void run_deep_copy_tests()
{
	std::cout << "\n\n--- Running Deep Copy Tests ---" << std::endl;

	// --- Testing Dog Copy constructor ---
	std::cout << "\n--- Testing Dog Copy Constructor ---" << std::endl;
	Dog original_dog;
	original_dog.setIdea(0, "chase the mailman");
	original_dog.setIdea(1, "Bury the bone");

	// Create a copy using the copy constructor
	Dog copied_dog(original_dog);

	std::cout << "Original Dog's first idea: " << original_dog.getIdea(0) << std::endl;
	std::cout << "Copied Dog's first idea: " << copied_dog.getIdea(0) << std::endl;

	std::cout << "\n-> Changing original dog's idea..." << std::endl;
	original_dog.setIdea(0, "Nap on the couch");

	std::cout << "Original Dog's first idea is now: " << original_dog.getIdea(0) << std::endl;
	std::cout << "Copied Dog's first idea is still: " << copied_dog.getIdea(0) << std::endl;
	std::cout << "-> Different ideas means the constructor copy was DEEP" << std::endl;

	// --- Test Copy Assignment Operator ---
	std::cout << "\n--- Testing Cat Copy Assignment Operator ---" << std::endl;
	Cat cat1;
	cat1.setIdea(0, "Plot world domination");

	Cat cat2;
	cat2.setIdea(0, "Look cute for treats");

	std::cout << "Before assginment, Cat2's idea is: " << cat2.getIdea(0) << std::endl;
	cat2 = cat1;
	std::cout << "After assignment cat2 = cat1, Cat2's idea is: " << cat2.getIdea(0) << std::endl;

	std::cout << "\n-> Changing cat1's idea..." << std::endl;
	cat1.setIdea(0, "Knock things off the table");

	std::cout << "Cat1's idea is now: " << cat1.getIdea(0) << std::endl;
	std::cout << "Cat2's idea is still: " << cat2.getIdea(0) << std::endl;
	std::cout << "-> Different ideas means the assignment copy was DEEP" << std::endl;

	std::cout << "\n--- End of Deep Copy Tests. The Objects will be destroyed now. ---\n" << std::endl;
}

int main()
{
	run_subject_tests();
	run_deep_copy_tests();
	return 0;
}
