/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 23:26:34 by anemet            #+#    #+#             */
/*   Updated: 2025/10/24 19:39:12 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "Zombie.hpp"

/* C++ new[]
	The `new Zombie[N] does the following:
	1.	Calculates the total memory needed for N contiguous Zombie objects.
	2.	Allocates that block of memory from the heap
	3.	Calls the default constructor `Zombie::Zombie()` for each of the N elements
	4.	Returns a pointer to the very first Zombie object in the array.
*/
Zombie* zombieHorde(int N, std::string name)
{
	// allocate N zombies on the heap in a single allocation
	// the `horde` pointer points to the first zombie (index 0)
	Zombie* horde = new Zombie[N];

	// Loop through the array and rename each zombie.
	for (int i = 0; i < N; i++)
	{
		std::ostringstream oss;			// oss <- output string stream
		oss << name << "[" << i << "]";	// can mix strings, ints, etc.
		horde[i].setName(oss.str());	// but in the end we convert it to string with oss.str()
	}

	return horde;
}
