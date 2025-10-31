/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:26:11 by anemet            #+#    #+#             */
/*   Updated: 2025/10/31 10:32:45 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp" // update to AAnimal
# include "Brain.hpp"

// Cat also inherits from Animal, just like Dog
class Cat : public AAnimal
{
	private:
		Brain* _brain;
	public:
		// --- Orthodox Canonical Form ---
		Cat();
		Cat(const Cat &ohter);
		Cat &operator=(const Cat &other);
		~Cat();

		// -- Member functions ---
		// Overriding makeSound() for the Cat class
		virtual void makeSound() const;
		void setIdea(int index, const std::string& idea);
		const std::string& getIdea(int index) const;
};

#endif
