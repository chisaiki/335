# Problem 1: Matrix 3 x 3

``` 
For each of the functions above(number 3-14) tell me the big O run time and space time of your algorithm with an explanation. 
```

**Solution:** Its is all O(1) because all operations are finite and a constant number. It does not scale since input size of the array is not increasing. Space complexity is also constant, because at most one new 3 x 3 array is created to store results, it does not grow or shrink with input size.


# Problem 3: Matrix n x m
``` 
For each of the functions above(number 3-14) tell me the big O run time and space time of your algorithm with an explanation. 
```

3. Default Constructor
    <br> The time complexity is **O(1)** because it is a default constructor and has constant time initialization.
    <br> The space complexity is **O(1)** since there is no memory allocation.

4. Parameterized Constructor
    <br> The time complexity is **O(n × m)** for copying array data into vector.
    <br> The space complexity is **O(n × m)** for storing the matrix data.

5. Copy Constructor
    <br>The time complexity is **O(n × m)** where n is the number of rows and m is the number of columns.
    This is where the complexity comes from the copy assignment which must copy **every element** for a 2D vector with n rows and m columns, this means copying n × m integers.
    <br>The space complexity is **O(n × m)** for storing the copied matrix and grows based on the number of elements it has to copy.

6. Move Constructor
    <br> The complexity and space complexity **O(1)** because it is simply transfering ownership so no new memory is allocated; and there is only a finite set of operations done. 

7. Copy Assignment
    <br> The time complexity is **O(n × m)** where n is the number of rows and m is the number of columns since it is copying the matrix data from one object to another.
    <br>The space complexity is **O(n × m)** for storing the copied matrix to another object, it creates a deep copy of all n × m elements. (Same as copy constructor.)

8. Move Assignment
     <br> The complexity and space complexity **O(1)** because it is simply transfering ownership so no new memory is allocated; and there is only a finite set of operations done. (Same as move constructor.)

9. '*' Operator
    <br> The time complexity is **O(n × m x l)** where n is the number of rows in the first matrix, m is the number of columns in the first matrix / rows in the second matrix, and l is the number of the columns in the second matrix. In order to do the multiplication we have to multiply each row of Matrix A to multiplied by each column of Matrix B. 
    <br> The space complexity is **O(n x l)** since it will create a new matrix with the dimensions of the rows from Matrix A and the columns from Matrix B.

10. '*' Operator Scalar
    <br> The time complexity is **O(n × m)** where n is the number of rows and m is the number of columns since it is multiplying every element in the matrix to a single scalar value. This requires visiting each element exactly once.
    <br>The space complexity is **O(n x m)** since it will create a new matrix of the same size to store the new data.

11. '+' Operator
    <br> The time complexity is **O(n × m)** where n is the number of rows and m is the number of columns since it is adding corresponding elements of both matrices to each other.
    <br>The space complexity is **O(n x m)** since it will create a new matrix of the same size to store the new data.

12. '<<' Operator
    <br> The time complexity is **O(n × m)** where n is the number of rows and m is the number of columns; since we are visiting every element in the matrix to print, we have to iterate through n rows and m columns.
    <br> The space complexity is **O(1)** because it is simply printing an existing matrix so no new memory is allocated.

13. '>>' Operator
    <br> The time complexity is **O(n × m)** where n is the number of rows and m is the number of columns; since we are visiting every element in the matrix to input the value given by the user, we have to iterate through n rows and m columns.
    <br> The space complexity is **O(1)** because it is writing in data an existing matrix so no new memory is allocated.

14. Determinant
    <br>The time complexity is **O(n!)** where n is the dimension of the square matrix. This comes from the cofactor expansion algorithm which recursively calculates n smaller determinants for each element in the first row, leading to factorial growth.
    <br>The space complexity is **O(n²)** due to the recursion stack (O(n) depth) and the creation of minor matrices (O(n²) each) at each recursive level.

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