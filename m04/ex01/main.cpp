/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 21:27:58 by anemet            #+#    #+#             */
/*   Updated: 2025/10/30 21:39:17 by anemet           ###   ########.fr       */
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

int main()
{
	run_subject_tests();
	return 0;
}
