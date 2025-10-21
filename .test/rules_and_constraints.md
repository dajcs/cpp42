## C++ Rules and Constraints for 42 School Projects

- compile the code with: `c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o program`
- class names in UpperCamelCase format.  \
Files containing class code will be named according to the class name, e.g., 
`ClassName.hpp`/`ClassName.h`, `ClassName.cpp` or `ClassName.tpp`.
- External Libraries are forbidden: it means C++11 (and derived forms) and Boost libraries are forbidden.
- Forbidden functions: `*printf()`, `*alloc()` and `*free()`.
- Unless otherwise specified, the using `namespace <ns_name>;` and `friend` keywords are forbidden.
- `STL` containers are forbidden, (except in Modules 08 and 09). That means no **Containers** (`std::vector`, `std::list`, `std::map`, etc.) and no **Algorithms** (anything that requires including the `<algorithm>` header)

### Design Requirements:
- avoid memory leaks
- In Modules 02 to 09 the classes must be designed in the Orthodox Canonical Form (except when stated otherwise). 
- No function implementation in the header files (except for function templates)
- It should be possible to use each header independently from others. Thus they must include all the dependencies they need. Double inclusion must be avoided by adding **include guards**. 
