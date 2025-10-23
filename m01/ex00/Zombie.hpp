/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:53:55 by anemet            #+#    #+#             */
/*   Updated: 2025/10/23 20:04:30 by anemet           ###   ########.fr       */
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
		// constructor
		Zombie(std::string name);

		//destructor
		~Zombie(void);

		// A regular member function that can be called on any Zombie object
		void announce(void);

};

// Function prototypes
Zombie *newZombie(std::string name);
void	randomChump(std::string name);

#endif
