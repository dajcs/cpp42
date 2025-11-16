/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 10:37:00 by anemet            #+#    #+#             */
/*   Updated: 2025/11/16 11:06:26 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.hpp"
#include <iostream>

void run_subject_tests()
{
	std::cout << "--- SUBJECT TESTS ---" << std::endl;

	const bigint a(42);
	bigint b(21), c, d(1337), e(d);

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "e = " << e << std::endl;

	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "(c += a) = " << (c += a) << std::endl;

	std::cout << "b = " << b << std::endl;
	std::cout << "++b = " << ++b << std::endl;
	std::cout << "b++ = " << b++ << std::endl;

	std::cout << "(b << 10) + 42 = " << ((b << 10) + 42) << std::endl;
	std::cout << "(d <<= 4) = " << (d <<= 4) << std::endl;
	std::cout << "(d >>= 2) = " << (d >>= (const bigint)2) << std::endl;

	std::cout << "a =" << a << std::endl;
	std::cout << "d =" << d << std::endl;

	std::cout << "(d < a) = " << (d < a) << std::endl;
	std::cout << "(d <= a) = " << (d <= a) << std::endl;
	std::cout << "(d > a) = " << (d > a) << std::endl;
	std::cout << "(d >= a) = " << (d >= a) << std::endl;
	std::cout << "(d == a) = " << (d == a) << std::endl;
	std::cout << "(d != a) = " << (d != a) << std::endl;
}


void run_additional_tests ()
{
	std::cout << "\n--- ADDITIONAL TESTS ---" << std::endl;

	// Addition with carry
	bigint n1(99);
	bigint n2(1);
	std::cout << "bigint(99) + bigint(1) = " << (n1 + n2) << std::endl;

	// Construction from strange values
	std::cout << "bigint(-1) = " << bigint(-1) << std::endl;
	std::cout << "bigint(0.001) = " << bigint(0.001) << std::endl;
	std::cout << "bigint(1e14) = " << bigint(1e14) << std::endl;
	std::cout << "bigint(1.1e15) = " << bigint(1.1e15) << std::endl;
	std::cout << "bigint(1.1e17) = " << bigint(1.1e17) << std::endl;
	std::cout << "bigint(1.234567890123456789e18) = " << bigint(1.234567890123456789e18) << std::endl;
	// compilation error: overflow at `double` to `long long` conversion
	// std::cout << "bigint(1.11e19) = " << bigint(1.11e19) << std::endl;

}


int main()
{
	run_subject_tests();
	run_additional_tests();
}
