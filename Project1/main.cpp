#include <iostream>
#include "Matrix33.h"


int main()
{
    Matrix33 firstMatrix;

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


    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << array[i][j];
        }

        std::cout << std::endl;
    }

    firstMatrix.printFunc();
}