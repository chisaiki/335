# Errors I Ran Into

## Syntax Errors
1. 
``` 
Matrix33::printFunc()
{
    std::cout << "\nPrint Function Called" << std::endl;
}
```
This is wrong because I need to declare the function type before I specify the scope of the function itself

Correct: ``` void Matrix33::printFunc() ```

2. **Implicitly-Declared Error** occured because you declared a copy constructor in your .cpp file without declaring it in the header file

3. ``` std::cout << "Address: " << &Matrix << std::endl; ```
    I wanted to get the address of the array, the first element to see if the move constructor was working, but it kept returning different addresses. This is because this code is asking for the address of the pointer itself, not the address that the pointer is holding. 

4. Copy Assignment Operator Error
    ```
    /*Copy Assignment Operator*/
    Matrix33& operator=(const Matrix33& otherObject)
    {
        std::cout << "\nCopy Assignment Operator Called" << std::endl;
        
        if (this != &otherObject) {
                delete Matrix;
                Matrix = new int(*otherObject.Matrix);
            }
            return *this;
    }
    ```

    This is wrong because I need to manually free all the data in the 3x3 matrix since its not a single data point, but an array of pointers.

5. If its inside the class you don't need scope resolution operator ClassName::

```
Incorrect Code: Matrix33& operator=(Matrix33&& otherObject)
Correct Code: Matrix33& Matrix33::operator=(Matrix33&& otherObject)
```
Since I'm working on seperate files (implementation/declaration) I need to use the scope resolution operator.

6. ``` Matrix33 Matrix33::operator<<() ``` 
This is wrong because the << operator *must* be a non-member (aka friend function) to access the class’s private data (3x3 Matrix pointer). By declaring it as a friend, you allow the operator function to access private and protected members of your class, so it can print the matrix contents directly.

    **Summary:**  
    - `friend` gives the operator access to private members.
    - This is necessary for printing internal data that isn’t public.



## Questions:
1. Why do I need a constructor?
   - You need a constructor to initialize your object’s data members when you create an instance of the class. Constructors set up the initial state of your object, allocate memory if needed, and help prevent bugs from uninitialized variables.

   -  C++ automatically provides a default constructor for you. This is called the compiler-generated default constructor. **It does not initialize member variables**; it just creates the object.

   - However, if you define *any* constructor (even one with parameters), the compiler will not generate a default constructor unless you explicitly declare it. If you want both a custom constructor and a default one, you must define the default constructor yourself.

   - Because I'm writing my own constructors, I need to provide a default one as well, because of the above reason

   ```
   In summary, C++ allows objects to be created without explicit initialization, but it's crucial to understand the implications. Default initialization of built-in types leaves them with indeterminate values, while class types are default-initialized by their constructors. Always strive to initialize objects properly to avoid undefined behavior and potential issues.
   ```