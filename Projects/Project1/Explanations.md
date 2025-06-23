# Problem 1: Matrix 3 x 3

``` 
For each of the functions above(number 3-14) tell me the big O run time and space time of your algorithm with an explanation. 
```

**Solution:** Its is all O(1) because all operations are finite and a constant number. It does not scale since input size of the array is not increasing. Space complexity is also constant, because at most one new 3 x 3 array is created to store results.

# Problem 2

# Problem 3: Matrix n x m
``` 
For each of the functions above(number 3-14) tell me the big O run time and space time of your algorithm with an explanation. 
```

1. Default Constructor
2. Parameterized Constructor
3. Copy Constructor
4. Move Constructor
5. Copy Assignment
6. Move Assignment
7. '*' Operator
8. '*' Operator Scalar
9. '+' Operator
10. '<<' Operator
11. '>>' Operator
14. Determinant



# To Test Matrix N x M 
```
#include <iostream>
#include <vector>
#include <stdexcept>
#include "Matrixnm.h"
#include "vector3.h"

int main()
{
    try{

     /*Test Matrix Addition - Create two valid matrices*/
    int array1[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int array2[2][3] = {{7, 8, 9}, {10, 11, 12}};
    int array3[3][2] = {{7, 8}, {9, 10}, {11, 12}};
    
    Matrixnm matrix1(2, 3, (int*)array1);
    Matrixnm matrix2(2, 3, (int*)array2);
    Matrixnm matrix3(3, 2, (int*)array3);
    
    std::cout << "Matrix 1:\n" << matrix1 << std::endl;
    std::cout << "Matrix 2:\n" << matrix2 << std::endl;
    
     /*Test matrix addition - this might throw if dimensions don't match*/
        try {
            Matrixnm addResult = matrix1 + matrix3;  // Different dimensions!
            std::cout << "Matrix 1 + Matrix 3:\n" << addResult << std::endl;
        } catch (const std::invalid_argument& e) {
            std::cout << "Addition Error: " << e.what() << std::endl;
        }

        /*Test matrix multiplication*/
        try {
            Matrixnm multResult = matrix1 * matrix3;
            std::cout << "Matrix 1 * Matrix 3:\n" << multResult << std::endl;
        } catch (const std::invalid_argument& e) {
            std::cout << "Multiplication Error: " << e.what() << std::endl;
        }

        /*Test scalar multiplication*/
        try {
            Matrixnm scalarResult = matrix1 * 3;
            std::cout << "Matrix 1 * 3:\n" << scalarResult << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Scalar Multiplication Error: " << e.what() << std::endl;
        }
     } catch (const std::invalid_argument& e) {
        std::cout << "Invalid Argument Error: " << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cout << "General Error: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cout << "Unknown error occurred!" << std::endl;
        return 1;
    }

    std::cout << "Program completed successfully!" << std::endl;
    return 0;
    
}
```