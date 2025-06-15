#include <iostream>
#include "1.h"

Matrix33::Matrix33(){
    std::cout << "\nI think anthony is cute\n";

} /*Just reserves empty memory space*/

Matrix33::Matrix33(int& matrixArray)
{
    std::cout << "\nCustom Construstor Created";

    /*For each row, make 3 memory spaces for the columns*/
    for (int i = 0; i < 3; ++i) 
    {
        matrix_ptr[i] = new int[3];
    }

    
    int value = 3;
    for (int i = 0; i < 3; ++i) 
    {
        for (int j = 0; j < 3; ++j) {
           matrixArray[i][j] = value++;
        }
    }
}

Matrix33::matrix33Copy (const Matrix33& previousMatrixObject)
{
    std::cout << "Copy Constructor has been called!\n";
    matrix_ptr = new int*[3];

    /*For each row, make 3 memory spaces for the columns*/
    for (int i = 0; i < 3; ++i) 
    {
        matrix_ptr[i] = new int[3];
    }


    for (int i = 0; i < 3; ++i) 
    {
        for (int j = 0; j < 3; ++j) {
            matrix_ptr[i][j] = previousMatrixObject[i][j];
        }
    }

    std::cout << "\nStart of previous";
    for (int i = 0; i < 3; ++i) 
    {
        for (int j = 0; j < 3; ++j) {
            std::cout << " " << previousMatrixObject[i][j] << " ";
        }

        std::cout << std::endl;
    }
    
    std::cout << "\nStart of current";
    for (int i = 0; i < 3; ++i) 
    {
        for (int j = 0; j < 3; ++j) {
            std::cout << " " << matrix_ptr[i][j] << " ";
        }

        std::cout << std::endl;
    }
}

/* int test()
{
    int value = 1;
    for (int i = 0; i < 3; ++i) 
    {
        for (int j = 0; j < 3; ++j) {
            matrix_ptr[i][j] = value++;
        }
    }

    for (int i = 0; i < 3; ++i) 
    {
        for (int j = 0; j < 3; ++j) {
            std::cout << " " << matrix_ptr[i][j] << " ";
        }

        std::cout << std::endl;
    }
} */