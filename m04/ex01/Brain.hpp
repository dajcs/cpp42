/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 18:59:37 by anemet            #+#    #+#             */
/*   Updated: 2025/10/30 19:01:57 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string.h>
# include <iostream>

class Brain
{
	public:
		// The array of ideas as a public member, as per subject
		std::string ideas[100];

		// --- Orthodox Canonical Form ---
		Brain();
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
		~Brain();
};

#endif
