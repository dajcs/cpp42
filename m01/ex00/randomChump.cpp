/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 22:22:05 by anemet            #+#    #+#             */
/*   Updated: 2025/10/23 22:27:07 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
	This function creates a Zombie on the STACK.

	When we declare a variable like `Zombie chump = Zombie(name);`, the object is created
	directly on the stack. It is a local variable, just like an `int` or a `char`.

	Its lifetime is tied to its scope (the curly braces `{...}` of the function).
	When the `randomChump` function finishes executing and returns, all of its local
	variables are automatically destroyed. This means the `chump` object's destructor
	(`~Zombie`) will be called automatically. No `new` or `delete` is needed.
*/
void randomChump(std::string name)
{
	Zombie chump = Zombie(name);
	chump.announce();
}	// <-- The `chump` object's destructor is automatically called right here!
