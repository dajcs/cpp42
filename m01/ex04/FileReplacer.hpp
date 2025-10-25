/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 07:06:13 by anemet            #+#    #+#             */
/*   Updated: 2025/10/25 10:40:23 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEREPLACER_HPP
# define FILEREPLACER_HPP

# include <string>

class FileReplacer
{
	private:
		std::string _inputFile;
		std::string _outputFile;
		std::string _s1;
		std::string _s2;
		size_t		_replacementCount;

	public:
		// Constructor takes 3 cmd line args
		FileReplacer(std::string filename, std::string s1, std::string s2);
		~FileReplacer(void);

		// The main method that orchestrates the replacement process
		void replace(void);
		// A "getter" to retrieve the final count
		// "const" because calling it doesn't change the object
		size_t getReplacementCount(void) const;
};


#endif
