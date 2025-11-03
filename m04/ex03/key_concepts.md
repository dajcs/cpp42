# Key Concepts in this Project

1. **Interface (Pure Abstract Class)**: An interface defines a contract. It declares a set of public methods that a concrete class must implement, but it provides no implementation itself. This is how you enforce a certain behavior ar API on a group of unrelated classes. In this project `ICharacter` and `IMateriaSource` are interfaces.
Any class that inherits from them *must* provide code for `getName()`, `equip()`, `learnMateria()`, etc. This guarantees that any `ICharacter` pointer, no matter what concrete character it points to, will have those functions available.
2. **Factory Pattern (`MateriaSource`)**: The `MateriaSource` class is a simple implementation of the *Factory design pattern*. Its job is not to be a thing, but to create other things (in this case, `AMateria` objects). You "teach" the factory with templates, and then you can ask it to produce new objects by name. This decouples the code that uses Materias (like `Character`) from the code that creates them (`new Ice()`, `new Cure()`, etc.).
3. **Cloning (`clone()` method)**: The `clone()` virtual function is a common C++ idiom for solving the problem of "how to copy a derived class object when you only have a base class pointer". If you have an `AMateria*` that actually points to an `Ice` object, you can't just write `new AMateria(*ptr)` because `AMateria` is abstract. Instead, you call `ptr->clone()`, which will invoke the `Ice`'s implementation of `clone()` and return a new `Ice` object, a perfect copy of itself, whatever its actual derived type is.
4. **Ownership and Memory Management**: This project is a major test of your memory management skills. You must be crystal clear about who "owns" a dynamically allocated object and is responsible for deleting it.
    - A `Character` **owns** the `AMateria`-s in its inventory. It must `delete` them in its destructor and assignment     operator.
    - When a `Character` `unequip`-s an `AMateria`, it gives up ownership. The caller is now responsible for that     poiner. If you don't save it, you have a memory leak.
    - A `MateriaSource` owns the "template" `AMateria`-s it learns. It must delete them in its destructor.
    - The `main` function (or any caller) **owns** any `AMateria` returned by `MateriaSource::createMateria()`. It must     either `equip` it (transferring ownership to the `Character`) or `delete` it manually.


Interface header files (e.g., `ICharacter.hpp`, `IMateriaSource.hpp`) define the contracts. They have no corresponding `.cpp` files because they contain no implementation.



# Graphical Diagram of the Class Relationships

Here is an ASCII diagram that illustrates the inheritance and composition relationships in your project, followed by a detailed explanation.

```
===================================================================================
                                 THE LEGEND
-----------------------------------------------------------------------------------
[ ClassName ]      - A concrete class that can be instantiated.
< InterfaceName >  - An interface (pure abstract class) that cannot be instantiated.
{ AbstractClass }  - An abstract base class that cannot be instantiated.

       ^
       |           - Inheritance ("is-a" relationship). The class below
   (implements/    - inherits from or implements the one above.
    inherits)

  - - - - >      - Composition/Usage ("has-a" or "uses-a" relationship).
 (has-a/uses-a)    - One class contains or uses another.
===================================================================================


     < ICharacter >                                       < IMateriaSource >
           ^                                                      ^
           | (implements)                                         | (implements)
           |                                                      |
    [ Character ]                                          [ MateriaSource ]
           |                                                      |
           |                                                      |
           ' - - - - - - has an inventory of [AMateria*] - - - - -'
                                   |                              |
                                   |                              ' - - learns/creates - > { AMateria }
                                   |                                                       (Abstract)
                                   ' - - - - - - - - - - - - - - - - - - - - - - - - - > ^
                                                                                         | (inherits)
                                                                              +----------+----------+
                                                                              |                     |
                                                                         [  Ice  ]             [  Cure  ]
```

## Explanation of the Diagram

Explanation of the core components:

#### 1. The Interfaces (The Contracts)

*   **`<ICharacter>` and `<IMateriaSource>`**: These are at the very top of their respective hierarchies. They are "interfaces" (pure abstract classes).
    *   They define a set of rules or a "contract."
    *   `ICharacter` says: "Anyone who claims to be a character *must* have a `getName()`, `equip()`, `unequip()`, and `use()` method."
    *   `IMateriaSource` says: "Any class that acts as a materia source *must* have a `learnMateria()` and `createMateria()` method."
    *   You cannot create an object of type `ICharacter` directly. You can only have a pointer or reference to it (e.g., `ICharacter* me;`).

#### 2. The Concrete Implementations

*   **`[Character]` and `[MateriaSource]`**: These are the concrete classes that fulfill the contracts defined by the interfaces.
    *   The arrow `^` pointing from `[Character]` up to `<ICharacter>` shows this relationship: **`Character` implements `ICharacter`**. This means `Character` provides the actual code for all the pure virtual functions in its parent interface.
    *   Similarly, **`MateriaSource` implements `IMateriaSource`**.

#### 3. The Materia Hierarchy

*   **`{AMateria}`**: This is an **abstract base class**. It's similar to an interface, but it's not "pure" because it contains data (`_type`) and can have some implemented methods. However, because it contains the pure virtual function `clone() = 0`, it is abstract and cannot be instantiated.
    *   Its purpose is to define the common behavior and properties of all "Materias."

*   **`[Ice]` and `[Cure]`**: These are concrete types of Materia.
    *   The arrows pointing up from `[Ice]` and `[Cure]` to `{AMateria}` show that they **inherit from `AMateria`**. This means an `Ice` **is an** `AMateria`, and a `Cure` **is an** `AMateria`. This is the foundation of polymorphism.
    *   Because they inherit from an abstract class, they are required to provide an implementation for the `clone()` method.

#### 4. The Key Relationships (The Dashed Lines)

These lines show how the different parts of the system interact with each other. This is "composition" or "usage," where one object holds or uses another.

*   **`[Character]` - - - > `[AMateria*]`**: This is the most important relationship.
    *   A `Character` **has an** inventory, which is an array of `AMateria` pointers.
    *   It does **not** hold `Ice` or `Cure` objects directly. It holds `AMateria` pointers. This allows the inventory to store *any* kind of `AMateria` (`Ice`, `Cure`, or any other future type) without the `Character` class needing to know the specifics. This is polymorphism in action.

*   **`[MateriaSource]` - - > `{AMateria}`**: This shows the "Factory" pattern.
    *   A `MateriaSource` **learns** `AMateria` templates by storing them in an internal array.
    *   It **creates** new `AMateria` objects on demand. The user asks for an "ice" materia by string, and the factory clones its `Ice` template and returns a new `AMateria` pointer. This decouples the creation of objects from their usage.
