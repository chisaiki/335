#include <iostream>
#include "Matrix33.h"

Matrix33::Matrix33(){
    std::cout << "\nI think anthony is cute\n";
} /*Just reserves empty memory space*/

Matrix33::Matrix33(int& matrixArray)
{
    std::cout << "\nCustom Construstor Created";
}

Matrix33::Matrix33 (const Matrix33& previousMatrixObject)
{
    std::cout << "Copy Constructor has been called!\n";
    matrix_ptr = new int*[3];
}