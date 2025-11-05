/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:05:53 by anemet            #+#    #+#             */
/*   Updated: 2025/11/05 17:24:06 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// Providing empty definitions for the private constructor/destructor
// to satisfy the linker, even though they can't be called from outside
Serializer::Serializer() {}
Serializer::Serializer(const Serializer& other) { (void)other; }
Serializer& Serializer::operator=(const Serializer& other) { (void)other; return *this; }
Serializer::~Serializer() {}

/*
** `reinterpret_cast<new_type>(expression)`:**
	This is the C++ way of doing a forced, unsafe type conversion.
	It's conceptually similar to a C-style cast like `(uintptr_t)ptr`,
	but it's more explicit and easier to find in code.
	C++ provides different `cast` operators
		- `static_cast`
		- `dynamic_cast`
		- `const_cast`
		- `reinterpret_cast`
	for different situations to make code safer and more readable.
	`reinterpret_cast` is specifically for re-interpreting bit patterns.
*/

// This function takes a pointer to a Data object...
uintptr_t Serializer::serialize(Data* ptr)
{
	//... and uses reinterpret_cast to convert that pointer to uintptr_t
	// this cast is interpreting underlying bits of the pointer as unsigned
	// integer, but it doesn't change the bits themselves
	return reinterpret_cast<uintptr_t>(ptr);
}

// This function takes a uintptr_t integer
Data* Serializer::deserialize(uintptr_t raw)
{
	// ... and uses reinterpret_cast to convert the integer back to a pointer
	// to a Data object. This is the reverse operation of serialize.
	// If 'raw' holds the bit pattern of a valid memory address, the
	// resulting pointer will be valid.
	return reinterpret_cast<Data*>(raw);
}
