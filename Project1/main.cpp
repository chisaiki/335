#include <iostream>
#include "Matrix33.h"


int main()
{
    int exampleArray[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    
    Matrix33 firstMatrix(exampleArray);

    int** array = new int*[3];
    for (int i = 0; i < 3; ++i) 
    {
        array[i] = new int[3];
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            array[i][j] == 0;
        }
    }

    //firstMatrix.printFunc();


    /*Testing Copy Constructor*/

    // Matrix33 newCopyObject(firstMatrix);
    // newCopyObject.printFunc();
    
    // Matrix33 a(exampleArray);
    // a.printFunc();
    // Matrix33 b = std::move(a); /*std::move makes this call the move constructor*/
    // b.printFunc();
    
    Matrix33 a(exampleArray);
    Matrix33 b(exampleArray);
    Matrix33 c = a * b;

    std::cout << c;

    std::cin >> c;
    std::cout << c;

}
