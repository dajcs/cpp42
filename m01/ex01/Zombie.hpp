/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:53:55 by anemet            #+#    #+#             */
/*   Updated: 2025/10/24 16:29:08 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string> // for std::string

class Zombie
{
	private:
		std::string _name;	// convention: private members prefixed with _

	public:
		// the default constructor - doesn't need name
		Zombie(void);

		// the parametrized constructor, constructs Zombie with a name
		Zombie(std::string name);

		//destructor
		~Zombie(void);

		// A regular member function that can be called on any Zombie object
		void announce(void);

		// A "setter" to set the name after creation
		void setName(std::string name);
};

// Function prototypes
Zombie* zombieHorde(int N, std::string name);

#endif
