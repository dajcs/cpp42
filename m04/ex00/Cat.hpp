/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:26:11 by anemet            #+#    #+#             */
/*   Updated: 2025/10/30 11:28:50 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

// Cat also inherits from Animal, just like Dog
class Cat : public Animal
{
	public:
		// --- Orthodox Canonical Form ---
		Cat();
		Cat(const Cat &ohter);
		Cat &operator=(const Cat &other);
		~Cat();

		// -- Member functions ---
		// Overriding makeSound() for the Cat class
		virtual void makeSound() const;
};

#endif
