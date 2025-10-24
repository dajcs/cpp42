/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 20:02:17 by anemet            #+#    #+#             */
/*   Updated: 2025/10/24 20:27:49 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	/*
		1. A string variable is initialized.
			This creates and object in memory that holds the text
	*/
	std::string brainString = "HI THIS IS BRAIN";

	/*
		2. Pointer to the string.
			`stringPTR` is a new variable that holds the memory address of `brainString`
			We're using the "address-of" operator '&' to get that address
	*/
	std::string* stringPTR = &brainString;

	/*
		3. A reference to the string
			`stringREF` is NOT a new variable. It is an alias for `brainString`.
			Any operation on `stringREF` will directly affect `brainString`.
			We're not using the '&' operator on the right side. We are not
			taking an address; we are creating a reference TO the variable.
	*/
	std::string& stringREF = brainString;


	/* --- PRINTING MEMORY ADDRESSES --- */
	std::cout << "--- MEMORY ADDRESSES ---" << std::endl;

	// To get the memory address OF the original variable, we use the '&' operator.
	std::cout << "Address of the string variable `brainString`: " << &brainString << std::endl;

	// The pointer `stringPTR` store the address to `brainString`, so we're just printing its value
	std::cout << "Address held by `stringPTR`:                : " << stringPTR << std::endl;

	// Using the '&' operator on a reference gives the address of the original variable it refers to,
	// so in the end `&stringREF` will show the same address as `&brainString`
	std::cout << "Address shown by `&stringREF`               : " << &stringREF << std::endl;
	std::cout << std::endl;


	/* --- PRINTING THE VALUES --- */
	std::cout << "--- VALUES ---"  <<  std::endl;

	// printing the value of `brainString`
	std::cout << "Value of the string variable `brainString`: " << brainString << std::endl;

	// to get the value AT the address stored in a pointer we "dereference" it with '*' operator
	std::cout << "Value pointed to by `stringPTR`           : " << *stringPTR << std::endl;

	// to print the value held by `stringREF` we just use its name
	std::cout << "Value referenced by `stringREF`:          : " << stringREF << std::endl;

}

