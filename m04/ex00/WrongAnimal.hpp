/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:34:23 by anemet            #+#    #+#             */
/*   Updated: 2025/10/30 12:56:49 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
	protected:
		std::string type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal &operator=(const WrongAnimal &other);
		// Note: the destructor is NOT virtual! This can lead to memory leaks.
		~WrongAnimal();

	// ---- Member functions -----
	/* makeSound() Note:
		This function is NOT virtual.
		This means the function to be called is decided at compile-time based
		on the pointer type (WrongAnimal*), not by the actual object type
		at runtime (WrongCat)
	*/
	void makeSound() const;
	const std::string &getType() const;
};

#endif
