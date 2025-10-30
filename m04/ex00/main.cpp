/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:14:47 by anemet            #+#    #+#             */
/*   Updated: 2025/10/30 14:50:42 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	// --- Provided Main Test ---
	std::cout << "--- Provided Main Test ---" << std::endl;
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << "Dog's type is: " << j->getType() << std::endl;
		std::cout << "Cat's type is: " << i->getType() << std::endl;
		std::cout << "Cat's sound: ";
		i->makeSound(); // will Meaow
		std::cout << "Dog's sound: ";
		j->makeSound(); // will Woof
		std::cout << "Animal's sound: ";
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}
	std::cout << std::endl;


	// --- wrongAnimal/WrongCat Test ---
	std::cout << "\n--- WrongAnimal/WrongCat Test ---\n" << std::endl;
	{
		const WrongAnimal* wrong_meta = new WrongAnimal();
		const WrongAnimal* wrong_cat = new WrongCat();

		std::cout << "WrongCat's type is: " << wrong_cat->getType() << std::endl;
		std::cout << "WrongCat's sound: ";
		/* No Polymorphism
			since makeSound() is not virtual in WrongAnimal, the compiler chooses
			which function to call based on the pointer type (WrongAnimal*).
			Therefore WrongAnimal::makeSound() is called, not WrongCat::makeSound().
		*/
		wrong_cat->makeSound();
		std::cout << "WrongAnimal's sound: ";
		wrong_meta->makeSound();
		std::cout << std::endl;

		// we can still call the WrongCat's sound directly if we have a WrongCat pointer.
		WrongCat* specific_wrong_cat = new WrongCat();
		std::cout << "Specific WrongCat's sound: ";
		specific_wrong_cat->makeSound();
		std::cout << std::endl;

		delete wrong_meta;
		delete wrong_cat; // this can lead to undefined behaviour/memory leaks
		delete specific_wrong_cat;	// because WrongAnimal's destructor is not virtual
	}


	// --- More Comprehensive Tests ---
	std::cout << "\n--- WrongAnimal/WrongCat Test ---\n" << std::endl;
	{
		// Test creating objects on the stack
		Dog dog;
		Cat cat;
		std::cout << "Stack Dog says: ";
		dog.makeSound();
		std::cout << "Stack Cat says: ";
		cat.makeSound();

		std::cout << "\n--- Testing Copy Constructor ---\n" << std::endl;
		Dog originalDog;
		Dog copiedDog(originalDog); // or Dog copiedDog = originalDog;
		std::cout << "Original Dog type: " << originalDog.getType() << std::endl;
		std::cout << "Copied Dog type: " << copiedDog.getType() << std::endl;
		std::cout << "Copied Dog says ";
		copiedDog.makeSound();

		std::cout << "\n--- Testing Copy Assignment Operator ---\n";
		Cat cat1;
		Cat cat2;
		cat2 = cat1; // assign cat1 to cat2
		std::cout << "Assigned Cat type: " << cat2.getType() << std::endl;
		std::cout << "Assigned cat says: ";
		cat2.makeSound();
		std::cout << std::endl;
	} // Stack objects dog, cat,... are automatically destroyed here

	return 0;
}

