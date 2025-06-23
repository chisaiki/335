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

6. In C++, you cannot define a function inside another function.

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
7. I used the wrong function type for getting matrix data
``` double& Matrix33::operator()(const Matrix33& matrixObject) ```
The operator() for a matrix class is used to access or modify an element at a specific row and column, so we want to use int.
```int& Matrix33::operator()(int row, int col);```

8. ``` b[i] += ((matrixObject.Matrix[i][j]) * (vectorObject[i])); ```
    You cannot access matrixObject.matrix[i][j] directly because matrix (actually Matrix) is a private member of the Matrix33 class. Private members can only be accessed from within the class's own methods or friend functions.

    How to access matrix values from outside the class:
    Use the public accessor I defined already [the overloaded operator()] :
    Correct Way: ``` matrixObject(i, j)```

9. int* existingArray -> expects int* (pointer to int), so you can't just pass the address of the first element<br>
   Without the cast, the compiler doesn't know that you want to treat the 2D array as a linear sequence of integers.



## Questions:
1. Why do I need a constructor?
   - You need a constructor to initialize your object’s data members when you create an instance of the class. Constructors set up the initial state of your object, allocate memory if needed, and help prevent bugs from uninitialized variables.

   -  C++ automatically provides a default constructor for you. This is called the compiler-generated default constructor. **It does not initialize member variables**; it just creates the object.

   - However, if you define *any* constructor (even one with parameters), the compiler will not generate a default constructor unless you explicitly declare it. If you want both a custom constructor and a default one, you must define the default constructor yourself.

   - Because I'm writing my own constructors, I need to provide a default one as well, because of the above reason

   ```
   In summary, C++ allows objects to be created without explicit initialization, but it's crucial to understand the implications. Default initialization of built-in types leaves them with indeterminate values, while class types are default-initialized by their constructors. Always strive to initialize objects properly to avoid undefined behavior and potential issues.
   ```

### Why does the matrix object being const cause an error in line 34?
   The error occurs because your `matrixObject` parameter in `getAx` is declared as `const Matrix33&`, but your `Matrix33::operator()(int row, int column)` is **not** marked as `const`.  

    This means you cannot call `matrixObject(i, j)` on a `const` object, because the compiler cannot guarantee that the function won't modify the object.

    **How to fix:**  
    Add a `const` qualifier to your accessor in `Matrix33.h` and `Matrix33.cpp`:

    ```cpp
    // In Matrix33.h
    int operator()(int row, int column) const;
    ```

    ```cpp
    // In Matrix33.cpp
    int Matrix33::operator()(int row, int column) const
    {
        return Matrix[row][column];
    }
    ```

    This allows you to access matrix elements from a `const Matrix33` object.  
    If you want to allow modification, keep the non-const version as well:

    ```cpp
    int& operator()(int row, int column);           // for modification
    int operator()(int row, int column) const;      // for read-only access
    ```

    **Summary:**  
    You need a `const` version of `operator()` to access elements of a `const Matrix33` object.