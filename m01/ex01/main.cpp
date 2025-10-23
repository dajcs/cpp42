/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 22:34:04 by anemet            #+#    #+#             */
/*   Updated: 2025/10/24 00:01:44 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main(void)
{
	const int hordeSize = 5; // use a constant for the size for clarity
	std::cout << "--- Creating a horde of " << hordeSize << " zombies! ---" << std::endl;

	// Create the horde of zombies on the heap
	Zombie* myHorde = zombieHorde(hordeSize, "Hordeling");

	// Test the horde by making each zombie announce itself
	for (int i = 0; i < hordeSize; i++)
	{
		myHorde[i].announce();
	}

	std::cout << "--- The horde has served its purpose. Time for cleanup. ---" << std::endl;

	/* C++ `delete[]`
		`myHorde` points to an ARRAY allocated with new[], we MUST use `delete[]` to deallocate it.
		`delete[] myHorde;` does the following:
		1.	It looks up how many objects are in the array (the compiler stores this info)
		2.	It calls the destructor `~Zombie()` for EVERY element in the array, from last to first.
		3. It deallocates the entire block of memory from the heap.

		note: command `delete myHorde;` without [] would delete only the first zombie.
	*/
	delete[] myHorde;

	return 0;
}
