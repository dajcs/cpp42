/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 10:35:36 by anemet            #+#    #+#             */
/*   Updated: 2025/10/31 10:58:43 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	std::cout << "\n--- Proving AAnimal is Abstract ---" << std::endl;
	/* AAnimal:
		The lines below cause a compilation error, uncomment to verify
	*/
	// AAnimal meta;
		// ERROR: unimplemented pure virtual method 'makeSound' in 'AAnimal'
	// const AAnimal* meta = new AAnimal();
		// ERROR: unimplemented pure virtual method 'makeSound' in 'AAnimal'

	// We can still create pointers and references of the abstract type
	// this is the whole point of abstract classes for polymorphism
	const AAnimal* dog = new Dog();
	const AAnimal* cat = new Cat();

	std::cout << std::endl;
	std::cout << "dog type: " << dog->getType() << std::endl;
	std::cout << "cat type: " << cat->getType() << std::endl;
	std::cout << "\ndog sound: " ;
	dog->makeSound();
	std::cout << "cat sound: " ;
	cat->makeSound();
	std::cout << std::endl;

	std::cout << "\n--- Deleting dog and cat (through AAnimal* pointer) ---\n" << std::endl;
	delete dog;
	delete cat;

	std::cout << "\n--- Testing with an array ---" << std::endl;
	const int array_size = 4;
	AAnimal* animals[array_size];

	// Fill the first half with Dogs
	for (int k = 0; k < array_size / 2; ++k)
	{
		animals[k] = new Dog();
		std::cout << std::endl;
	}

	// Fill the second half with Cats
	for (int k = array_size / 2; k < array_size; ++k)
	{
		animals[k] = new Cat();
		std::cout << std::endl;
	}

	// Make them all make a sound
	for (int k = 0; k < array_size; ++k)
	{
		animals[k]->makeSound();
	}
	std::cout << std::endl;

	// Delete the array
	for (int k = 0; k < array_size; ++k)
	{
		delete animals[k];
		std::cout << std::endl;
	}
	return 0;
}
