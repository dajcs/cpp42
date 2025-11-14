*  Can you help me with "bigint" project at 42 School?

---

- Files to turn in: `Makefile`, `main.cpp`, `bigint.hpp`, `bigint.cpp`
- Forbidden functions: None

---

Create a class called `bigint` that will store an arbitrary precision unsigned integer.

The class must support:
- Addition operator (`+`)
- Addition assignment operator (`+=`)
- Pre-increment and post-increment operators (`++`)
- Comparison operators (`==`, `!=`, `<`, `<=`, `>`, `>=`)
- "digshift" operators (`<<`, `>>`), but instead of shifting bits, they will shift decimal digits in base 10, e.g.: `42 << 3 == 42000` and `1337 >> 2 == 13`
- inplace "digshift" operators (`<<=`, `>>=`)
- must be printable with operator (`<<`) in base 10 and the output must not contain leading zeros (except for the number zero itself)

The class must work with the main provided below:

```cpp
#include "bigint.hpp"
#include <iostream>

int main()
{
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
```

- the class name: `bigint`
- store the number in a private member `std::string str`

As usual, submit more tests than the ones provided in the subject, to prove that your code works as expected in different situations.


---

*  Please put comments and give me explanations of what and why is done.

*  I don't have experience with C++, but I know C and I know object-oriented programming concepts. Please explain me how to implement this in C++ and everything what is new to me compared to C.

*  Please respect the C++ Rules and Constraints for 42 School Projects below:


## C++ Rules and Constraints for 42 School Projects

- compile the code with: `c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o program`
- class names in UpperCamelCase format.  \
- External Libraries are forbidden: it means C++11 (and derived forms) and Boost libraries are forbidden.
- Forbidden functions: `*printf()`, `*alloc()` and `free()`.
- Unless otherwise specified, the using `namespace <ns_name>;` and `friend` keywords are forbidden.
- `STL` containers are forbidden, (except in Modules 08 and 09). That means no **Containers** (`std::vector`, `std::list`, `std::map`, etc.) and no **Algorithms** (anything that requires including the `<algorithm>` header)

### Design Requirements:
- avoid memory leaks
- In Modules 02 to 09 the classes must be designed in the Orthodox Canonical Form (except when stated otherwise). The classes  will then implement:
  - Default constructor
  - Copy constructor
  - Copy assignment operator
  - Destructor
- No function implementation in the header files (except for function templates)
- It should be possible to use each header independently from others. Thus they must include all the dependencies they need. Double inclusion must be avoided by adding **include guards**.

