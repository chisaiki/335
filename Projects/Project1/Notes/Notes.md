## Definitions
- Instantiation
    This is when memory is allocated for an object. This is what the new keyword is doing. A reference to the object that was created is returned from the new keyword.

- Initialization
    This is when values are put into the memory that was allocated. This is what the Constructor of a class does when using the new keyword.
    A variable must also be initialized by having the reference to some object in memory passed to it.

- Declaration
    This is when you state to the program that there will be an object of a certain type existing and what the name of that object will be.


# Constructor Definitions

# Move Constructor
    Move constructor transfer the ownership of the already existing object to the new object *without making any copy* of it.

    We transfer the *ownership of the resources* from the old object to the new object and nullify the old object pointer.


## Why do I need to call move() to use my custom move constructor?

`std::move()` and your move constructor are **not the same thing**, but they work together:

- **Your move constructor** is the special function you wrote to transfer resources from one object to another (e.g., `Matrix33::Matrix33(Matrix33&& other)`).
- **`std::move()`** is a standard library function that casts an object to an rvalue reference, telling the compiler it can be "moved from."

**You use `std::move()` in your code to trigger (call) your move constructor.**  
Without `std::move()`, C++ will use the copy constructor by default when you pass an object by value.

**Example:**
````cpp
Matrix33 a(exampleArray);
Matrix33 b = std::move(a); /* std::move makes this call the move constructor */
````

**Summary:**  
- `std::move()` does not move anything by itself; it enables move semantics by casting.
- Your move constructor does the actual moving.
- Use `std::move()` when you want to transfer resources and avoid a deep copy.


## Why do we need to return a reference to the object (After a Copy Assignment Operator)?
    Returning a reference to the object (*this) in the assignment operator allows for assignment chaining and matches standard C++ behavior. For example, it lets you write:
    ``` a = b = b ```
    This works because b = c returns a reference to b, which is then assigned to a. Returning by reference also avoids unnecessary copying of the object. This is the standard and expected way to implement assignment operators in C++.

    A **reference** to an object in C++ is an alias for an existing object. It does not create a new object or copy the original; instead, it allows you to access and modify the original object using another name. References are declared using the & symbol.

    ## What is noexcept?
        noexcept signifies that a function either will not throw exceptions or that throwing an exception from it is a fatal error, leading to program termination. 