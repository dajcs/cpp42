/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 22:34:04 by anemet            #+#    #+#             */
/*   Updated: 2025/10/23 23:02:21 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main(void)
{
	// Demonstrating STACK allocation ---
	std::cout << "--- Creating a Zombie on the Stack (randomChump) ---" << std::endl;
	/*
	Calling randomChump. Inside this function, a Zombie "Stacky" will be created
	on the Stack, it will announce itself, and then it will be destroyed when
	the function returns.
	*/
	randomChump("Stacky");
	std::cout << "--- randomChump function has finished ---" << std::endl;
	std::cout << std::endl; // empty row for spacing


	// --- Demonstrating HEAP allocation ---
	std::cout << "--- Creating a Zombie on the Heap (newZombie) ---" << std::endl;
	/*
	Calling newZombie, which creates a Zombie on the Heap and returns a pointer to it.
	We store the pointer in `heapy`.
	*/
	Zombie* heapy = newZombie("Heapy");
	/*
	The `heapy` Zombie exists even the newZombie functino has finished.
	We can use the pointer to call its member functions.
	The `->` operator is used to access members of an object through a pointer,
	just like in C.
	*/
	heapy->announce();
	/*
	The `heapy` Zombie will exist forever, unless we manually destroy it.
	The `delete` keyword calls the object's destructor (`~Zombie`) and then frees
	the memory on the heap.
	*/
	std::cout << "--- Manually destroying the Heap Zombie ---" << std::endl;
	delete heapy;

	return 0;
}
