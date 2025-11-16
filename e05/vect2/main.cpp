/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 14:11:39 by anemet            #+#    #+#             */
/*   Updated: 2025/11/16 18:34:05 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "vect2.hpp"

void provided_tests()
{
	vect2 v1; // 0, 0
	vect2 v2(1, 2); // 1, 2
	const vect2 v3(v2); // 1, 2
	vect2 v4 = v2; // 1, 2

	std::cout << "v1: " << v1 << std::endl; // 0,0
	std::cout << "v1: " << "{" << v1[0] << ", " << v1[1] << "}" << std::endl;
	std::cout << "v2: " << v2 << std::endl; // 1,2
	std::cout << "v3: " << v3 << std::endl; // 1,2
	std::cout << "v4: " << v4 << std::endl; // 1,2

	std::cout << v4++ << std::endl; // 1,2 ->(2, 3)
	std::cout << ++v4 << std::endl; // 3, 4
	std::cout << v4-- << std::endl; // 3,4 ->(2, 3)
	std::cout << --v4 << std::endl; // 1, 2
	v2 += v3; // 2, 4
	v1 -= v2; // -2, -4
	v2 = v3 + v3 *2; // 3, 6
	v2 = 3 * v2; // 9, 18
	v2 += v2 += v3; // 20, 40
	v1 *= 42; // -84, -168
	v1 = v1 - v1 +v1;
	std::cout << "v1: " << v1 << std::endl; // -84, -168
	std::cout << "v2: " << v2 << std::endl; // 20, 40
	std::cout << "-v2: " << -v2 << std::endl; // -20, -40
	std::cout << "v1[1]: " << v1[1] << std::endl;  // -168
	v1[1] = 12;
	std::cout << "v1[1]: " << v1[1] << std::endl; // 12
	std::cout << "v3[1]: " << v3[1] << std::endl; // 2
	std::cout << "v1 == v3: " << (v1 == v3) << std::endl; // 0
	std::cout << "v1 == v1: " << (v1 == v1) << std::endl; // 1
	std::cout << "v1 != v3: " << (v1 != v3) << std::endl; // 1
	std::cout << "v1 != v1: " << (v1 != v1) << std::endl; // 0

}

void print_title(const std::string& title)
{
	std::cout << "\n--- " << title << " ---\n" << std::endl;
}

void more_tests()
{
	print_title("1. Constructors and Basic Output");
	vect2 v1; // Default constructor -> {0, 0}
	vect2 v2(1, 2); // Parameterized constructor -> {1, 2}
	const vect2 v3(v2); // Copy constructor -> {1, 2}
	vect2 v4 = v2; // Copy assignment -> {1, 2}

	std::cout << "v1 (default): " << v1 << std::endl;
	std::cout << "v1 (by index): " << "{" << v1[0] << ", " << v1[1] << "}" << std::endl;
	std::cout << "v2 (params): " << v2 << std::endl;
	std::cout << "v3 (copy of v2): " << v3 << std::endl;
	std::cout << "v4 (assigned from v2): " << v4 << std::endl;

	print_title("2. Increment and Decrement Operators");
	std::cout << "Initial v4: " << v4 << std::endl; // {1, 2}
	std::cout << "v4++ (post-increment): " << v4++ << std::endl; // Prints {1, 2}, v4 becomes {2, 3}
	std::cout << "v4 after post-increment: " << v4 << std::endl; // {2, 3}
	std::cout << "++v4 (pre-increment): " << ++v4 << std::endl; // Prints {3, 4}, v4 is {3, 4}
	std::cout << "v4 after pre-increment: " << v4 << std::endl; // {3, 4}
	std::cout << "v4-- (post-decrement): " << v4-- << std::endl; // Prints {3, 4}, v4 becomes {2, 3}
	std::cout << "v4 after post-decrement: " << v4 << std::endl; // {2, 3}
	std::cout << "--v4 (pre-decrement): " << --v4 << std::endl; // Prints {1, 2}, v4 is {1, 2}
	std::cout << "Final v4: " << v4 << std::endl; // {1, 2}

	print_title("3. Arithmetic and Assignment Operators");
	v1 = vect2(0,0); // Reset v1
	v2 = vect2(1,2); // Reset v2
	std::cout << "Initial v1: " << v1 << ", v2: " << v2 << ", v3: " << v3 << std::endl;

	v2 += v3; // v2 becomes {1,2} + {1,2} = {2, 4}
	std::cout << "v2 += v3 -> v2: " << v2 << std::endl;

	v1 -= v2; // v1 becomes {0,0} - {2,4} = {-2, -4}
	std::cout << "v1 -= v2 -> v1: " << v1 << std::endl;

	v2 = v3 + v3 * 2; // v2 = {1,2} + {2,4} = {3, 6}
	std::cout << "v2 = v3 + v3 * 2 -> v2: " << v2 << std::endl;

	v2 = 3 * v2; // v2 = 3 * {3,6} = {9, 18}
	std::cout << "v2 = 3 * v2 -> v2: " << v2 << std::endl;

	v2 += v2 += v3; // Chaining: v2 += v3 -> {10, 20}, then v2 += {10, 20} -> {20, 40}
	std::cout << "v2 += v2 += v3 -> v2: " << v2 << std::endl;

	v1 *= 42; // v1 = {-2,-4} * 42 = {-84, -168}
	std::cout << "v1 *= 42 -> v1: " << v1 << std::endl;

	v1 = v1 - v1 + v1; // Should result in v1 staying the same
	std::cout << "v1 = v1 - v1 + v1 -> v1: " << v1 << std::endl;


	print_title("4. Unary Minus and Index Access");
	std::cout << "Final v1: " << v1 << std::endl;
	std::cout << "Final v2: " << v2 << std::endl;
	std::cout << "Negated v2 (-v2): " << -v2 << std::endl;
	std::cout << "v1[1] (read): " << v1[1] << std::endl;
	v1[1] = 12; // Modify using [] operator
	std::cout << "v1[1] after assignment (v1[1] = 12): " << v1[1] << std::endl;
	std::cout << "v1 after modification: " << v1 << std::endl;
	std::cout << "v3[1] (read from const object): " << v3[1] << std::endl;
	// v3[1] = 5; // This would cause a compilation error because v3 is const.

	print_title("5. Comparison Operators");
	vect2 v5(v1);
	std::cout << "v1: " << v1 << ", v3: " << v3 << ", v5(copy of v1): " << v5 << std::endl;
	std::cout << "v1 == v3: " << (v1 == v3) << std::endl; // false
	std::cout << "v1 == v1: " << (v1 == v1) << std::endl; // true
	std::cout << "v1 == v5: " << (v1 == v5) << std::endl; // true
	std::cout << "v1 != v3: " << (v1 != v3) << std::endl; // true
	std::cout << "v1 != v1: " << (v1 != v1) << std::endl; // false
	std::cout << "v1 != v5: " << (v1 != v5) << std::endl; // false

}

int main()
{
	provided_tests();
	more_tests();
	return 0;
}
