*  Can you help me with "Polyset" project at 42 School?

---

- Files to turn in:  `main.cpp`, `searchable_array_bag.hpp`, `searchable_array_bag.cpp`, `searchable_tree_bg.hpp`, `searchable_tree_bg.cpp`, `set.hpp`, `set.cpp`
- Forbidden functions: None

---

You will find below definitions of several classes:
- `bag`: an abstract class, representing a bag
- `searchable_bag`: an abstract class representing a bag with the ability to search in it
- `array_bag`: an implementation of a bag with an array (as underlying data structure)
- `tree_bag`: an implementation of a bag with a binary tree (as underlying data structure)

First Part:

Since a bag without a searching function isn't very useful, implement two classes `searchable_array_bag` and `searchable_tree_bag`, inheriting respectively from `array_bag` and `tree_bag`, and implementing the `searchable_bag` abstract class.

Second Part:

Implement the class `set` that will wrap a `searchable_bag` and turn it into a set.

We provide you a `main` that must compile with your code.

All classes should be under orthodox canonical form. Don't forget the `const`.






As usual, submit more tests than the ones provided in the `main`, to prove that your code works as expected in different situations.


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


---

**bag.hpp**
```cpp

#pragma once

class bag {
public:
	virtual void insert (int) = 0;
	virtual void insert (int *, int) = 0;
	virtual void print() const = 0;
	virtual void clear() = 0;
};
```

**searchable_bag.hpp**
```cpp
#pragma once

#include "bag.hpp"

class searchable_bag : virtual public bag {
public:
	virtual bool has(int) const = 0;
};
```


**array_bag.hpp**
```cpp
#pragma once

#include "bag.hpp"

class array_bag : virtual public bag
{
 protected:
	int *data;
	int size;

 public:
	array_bag();
	array_bag(const array_bag &);
	array_bag &operator=(const array_bag &other);
	~array_bag();

	void insert(int);
	void insert(int *, int);
	void print() const;
	void clear();
};
```

**tree_bag.hpp**
```cpp
#pragma once

#include "bag.hpp"

class tree_bag : virtual public bag {
protected:
  struct node {
    node *l;
    node *r;
    int value;
  };
  node *tree;

public:
  tree_bag();
  tree_bag(const tree_bag &);
  tree_bag  &operator=(const tree_bag &);
  ~tree_bag();

  node *extract_tree();
  void set_tree(node *);

  virtual void insert(int);
  virtual void insert(int *array, int size);
  virtual void print() const;
  virtual void clear();

private:
  static void destroy_tree(node *);
  static void print_node(node *);
  static void *copy_node(node *);
};
```

**array_bag.cpp**
```cpp
#include "array_bag.hpp"
#include <iostream>

array_bag::array_bag() {
  size = 0;
  data = nullptr;
}

array_bag::array_bag(const array_bag &src) {
  size = src.size;
  data = new int[size];
  for (int i = 0; i < size; i++) {
	data[i] = src.data[i];
  }
}

array_bag &array_bag::operator=(const array_bag &src) {
	if (this != &src) {
		if (data != nullptr) {
			delete[] data;
			data = nullptr;
		}
		size = src.size;
		data = new int[size];
		for (int i = 0; i < size; i++) {
			data[i] = src.data[i];
		}
	}
	return *this;
}

array_bag::~array_bag() {
	if (data != nullptr) {
		delete[] data;
		data = nullptr;
	}
}

void array_bag::insert(int item) {
	int *new_data = new int[size + 1];
	for (int i = 0; i < size; i++) {
		new_data[i] = data[i];
	}
	new_data[size] = item;
	if (data != nullptr) {
		delete[] data;
	}
	data = new_data;
	size++;
}

void array_bag::insert(int *items, int count) {
	int *new_data = new int[size + count];
	for (int i = 0; i < size; i++) {
		new_data[i] = data[i];
	}
	for (int i = 0; i < count; i++) {
		new_data[size + i] = items[i];
	}
	if (data != nullptr) {
		delete[] data;
	}
	data = new_data;
	size += count;
}

void array_bag::print() const {
	for (int i = 0; i < size; i++) {
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}

void array_bag::clear() {
	if (data != nullptr) {
		delete[] data;
		data = nullptr;
	}
	size = 0;
}
```

**tree_bag.cpp**
```cpp
#include "tree_bag.hpp"
#include <iostream>

tree_bag::tree_bag() {
	tree = nullptr;
}

tree_bag::tree_bag(const tree_bag &src) {
	tree = copy_node(src.tree);
}

tree_bag::~tree_bag() {
	destroy_tree(tree);
}

tree_bag &tree_bag::operator=(const tree_bag &src) {
	if (this != &src) {
		destroy_tree(tree);
		tree = copy_node(src.tree);
	}
	return *this;
}

tree_bag::node *tree_bag::extract_tree() {
	node *temp = tree;
	tree = nullptr;
	return temp;
}

void tree_bag::set_tree(node *new_tree) {
	destroy_tree(tree);
	tree = new_tree;
}

void tree_bag::insert(int item) {
	node *new_node = new node;
	// alloc new node
	std::cout << "create node: " << item << std::endl;
	new_node->value = item;
	new_node->l = nullptr;
	new_node->r = nullptr;

	if (tree == nullptr) {
		// std::cout << "tree is null - adding" << std::endl;
		tree = new_node;
	} else {
		node *current = tree;
		while (true) {
			if (item < current->value) {
				if (current->l == nullptr) {
					current->l = new_node;
					break;
				} else {
					current = current->l;
				}
			} else if (item > current->value) {
				if (current->r == nullptr) {
					current->r = new_node;
					break;
				} else {
					current = current->r;
				}
			} else {
				std::cout << "duplicate value: delete node" << std::endl;
				delete new_node;
				break;
			}
		}
	}
}

void tree_bag::insert(int *items, int count) {
	for (int i = 0; i < count; i++) {
		insert(items[i]);
	}
}

void tree_bag::print() const {
	print_node(tree);
	std::cout << std::endl;
}

void tree_bag::clear() {
	destroy_tree(tree);
	tree = nullptr;
}

// defined as static functions in the class
void tree_bag::destroy_tree(node *current) {
	if (current != nullptr) {
		std::cout << "destroying value: " << current->value << std::endl;
		destroy_tree(current->l);
		destroy_tree(current->r);
		delete current;
	}
}

void tree_bag::print_node(node *current) {
	if (current != nullptr) {
		print_node(current->l);
		if (current->value != 0)
			std::cout << current->value << " ";
		print_node(current->r);
	}
}

tree_bag::node *tree_bag::copy_node(node *current) {
	if (current == nullptr) {
		return nullptr;
	} else {
		node *new_node = new node;
		new_node->value = current->value;
		new_node->l = copy_node(current->l);
		new_node->r = copy_node(current->r);
		return new_node;
	}
}
```

**main.cpp**
```cpp
#include "searchable_bag.hpp"

#include <iostream>

int main(int argc, char **argv) {
  if (argc == 1)
    return 1;
  searchable_bag *t = new searchable_tree_bag;
  searchable_bag *a = new searchable_array_bag;

  for (int i = 1; i < argc; i++) {
    t->insert(atoi(argv[i]));
    a->insert(atoi(argv[i]));
  }
  t->print();
  a->print();

  for (int i = 1; i < argc; i++) {
    std::cout << t->has(atoi(argv[i])) << std::endl;
    std::cout << a->has(atoi(argv[i])) << std::endl;
    std::cout << t->has(atoi(argv[i]) - 1) << std::endl;
    std::cout << a->has(atoi(argv[i]) - 1) << std::endl;
  }

  t->clear();
  a->clear();

  const searchable_array_bag tmp(static_cast<searchable_array_bag &>(*a));
  tmp.print();
  tmp.has(1);

  set sa(*a);
  set st(*t);
  for (int i = 1; i < argc; i++) {
    st.insert(atoi(argv[i]));
    sa.insert(atoi(argv[i]));

    sa.has(atoi(argv[i]));
    sa.print();
    sa.get_bag().print();
    st.print();
    sa.clear();
    sa.insert(
        (int[]){
            1,
            2,
            3,
            4,
        },
        4);
    std::cout << std::endl;
  }

  return 0;
}
```

