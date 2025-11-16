*  Can you help me with "vect2" project at 42 School?

---

- Files to turn in:  `main.cpp`, `vect2.hpp`, `vect2.cpp`
- Forbidden functions: None

---

Create a class called `vect2` representing a mathematical vector of dimension 2 containing ints.

It must support addition, subtraction and multiplication by scalar,
such as the expression (vect2(2,2) * 2 = vect2(4,4)).

The operator [] can be used to access the component of the vector (with 0 and 1), no bounds checking is required.

The function must be printable with the << operator, such as:

```cpp
std::cout << v << std::endl;
```

produce the same output as:

```cpp
std::cout << "{" << v[0] << ", " << v[1] << "}" << std::endl;
```

The main below must work with your class:

```cpp
#include <iostream>
#include "vect2.hpp"

int main()
{
    vect2 v1; // 0, 0
    vect2 v2(1, 2); // 1, 2
    const vect2 v3(v2); // 1, 2
    vect2 v4 = v2; // 1, 2

    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v1: " << "{" << v1[0] << ", " << v1[1] << "}" << std::endl;
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "v3: " << v3 << std::endl;
    std::cout << "v4: " << v4 << std::endl;
    std::cout << v4++ << std::endl; // 2, 3
    std::cout << ++v4 << std::endl; // 3, 4
    std::cout << v4-- << std::endl; // 2, 3
    std::cout << --v4 << std::endl; // 1, 2
    v2 += v3; // 2, 4
    v1 -= v2; // -2, -4
    v2 = v3 + v3 *2; // 3, 6
    v2 = 3 * v2; // 9, 18
    v2 += v2 += v3; // 20, 40
    v1 *= 42; // -84, -168
    v1 = v1 - v1 +v1;
    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "-v2: " << -v2 << std::endl;
    std::cout << "v1[1]: " << v1[1] << std::endl;
    v1[1] = 12;
    std::cout << "v1[1]: " << v1[1] << std::endl;
    std::cout << "v3[1]: " << v3[1] << std::endl;
    std::cout << "v1 == v3: " << (v1 == v3) << std::endl;
    std::cout << "v1 == v1: " << (v1 == v1) << std::endl;
    std::cout << "v1 != v3: " << (v1 != v3) << std::endl;
    std::cout << "v1 != v1: " << (v1 != v1) << std::endl;
}
```


As usual, submit more tests than the ones provided in the subject, to prove that your code works as expected in different situations.


---

*  Please put comments and give me explanations of what and why is done.

*  I don't have experience with C++, but I know C and I know object-oriented programming concepts. Please explain me how to implement this in C++ and everything what is new to me compared to C.

*  Please respect the C++ Rules and Constraints for 42 School Projects below:


## C++ Rules and Constraints for 42 School Projects

- compile the code with: `c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o program`
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

