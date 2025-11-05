/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:24:35 by anemet            #+#    #+#             */
/*   Updated: 2025/11/05 17:35:52 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // std::cout
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	// 1. Create an instance of the Data struct on the stack
	Data myData;
	myData.s1 = "Hello, Serialization!";
	myData.n = 42;

	// 2. Create a pointer to our Data object.
	Data* originalPtr = &myData;

	// --- Print original values for comparison ---
	std::cout << "--- ORIGINAL DATA ---" << std::endl;
	std::cout << "Original Pointer Address: " << originalPtr << std::endl;
	std::cout << "Original Data Content (s1): " << originalPtr->s1 << std::endl;
	std::cout << "Original Data Content (n): " << originalPtr->n << std::endl;
	std::cout << std::endl;

	// 3. Serialize the pointer
	// We call the static method on the Serializer class.
	// 'raw' now holds the numerical representation of the memory address.
	uintptr_t raw = Serializer::serialize(originalPtr);

	// --- Print serialized value ---
	std::cout << "--- SERIALIZATION PROCESS ---" << std::endl;
	// We print 'raw' in hexa to make it look like a memory address.
	std::cout << "Serialized to uintptr_t (raw): 0x" << std::hex << raw << std::dec << std::endl;
	std::cout << std::endl;

	// 4. Deserialize the raw integer back into a pointer
	Data* deserializedPtr = Serializer::deserialize(raw);

	// --- Print deserialized values ---
	std::cout << "--- DESERIALIZED DATA ---" << std::endl;
	std::cout << "Deserialized Pointer Address: " << deserializedPtr << std::endl;
	std::cout << "Deserialized Data Content (s1): " << deserializedPtr->s1 << std::endl;
	std::cout << "Deserialized Data Content (n): " << deserializedPtr->n << std::endl;
	std::cout << std::endl;

	// 5. Verificaton
	// The core of the test: check if the pointer we got back is the same as the one we started with
	std::cout << "--- VERIFICATION ---" << std::endl;
	if (deserializedPtr == originalPtr)
	{
		std::cout << "SUCCESS: The deserialized pointer is the same as the original pointer." << std::endl;
	}
	else
	{
		std::cout << "FAILURE: The pointers do NOT match." << std::endl;
	}

	return 0;
}
