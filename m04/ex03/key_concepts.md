# Key Concepts in this Project

1. **Interface (Pure Abstract Class)**: An interface defines a contract. It declares a set of public methods that a concrete class must implement, but it provides no implementation itself. This is how you enforce a certain behavior ar API on a group of unrelated classes. In this project `ICharacter` and `IMateriaSource` are interfaces.
Any class that inherits from them *must* provide code for `getName()`, `equip()`, `learnMateria()`, etc. This guarantees that any `ICharacter` pointer, no matter what concrete character it points to, will have those functions available.
