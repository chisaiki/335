# Errors I Ran Into

## Syntax Errors
``` 
Matrix33::printFunc()
{
    std::cout << "\nPrint Function Called" << std::endl;
}
```
This is wrong because I need to declare the function type before I specify the scope of the function itself

Correct: ``` void Matrix33::printFunc() ```

## Questions:
1. Why do I need a constructor?
   - You need a constructor to initialize your object’s data members when you create an instance of the class. Constructors set up the initial state of your object, allocate memory if needed, and help prevent bugs from uninitialized variables.

   -  C++ automatically provides a default constructor for you. This is called the compiler-generated default constructor. **It does not initialize member variables**; it just creates the object.

   - However, if you define *any* constructor (even one with parameters), the compiler will not generate a default constructor unless you explicitly declare it. If you want both a custom constructor and a default one, you must define the default constructor yourself.

   - Because I'm writing my own constructors, I need to provide a default one as well, because of the above reason

   ```
   In summary, C++ allows objects to be created without explicit initialization, but it's crucial to understand the implications. Default initialization of built-in types leaves them with indeterminate values, while class types are default-initialized by their constructors. Always strive to initialize objects properly to avoid undefined behavior and potential issues.
   ```