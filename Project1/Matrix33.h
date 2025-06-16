#ifndef _MATRIX33_H
#define _MATRIX33_H

#include <iostream>

class Matrix33
{
    public:

    Matrix33();
    Matrix33(int matrixArray[3][3]);

    /*Copy Constructor*/
    Matrix33(const Matrix33& other);

    /*Move Constructor*/
    Matrix33(Matrix33&& other);
    
    /*Copy Assignment Operator*/
    Matrix33& operator=(const Matrix33& otherObject);

    /*Move Assignment Operator*/
    Matrix33& operator=(Matrix33&& otherObject);

    /*Overload Operator for Matrix Multiplication*/
    Matrix33 operator*(const Matrix33& other) const;

    int& operator()(int row, int column) const;

    /*Overload Operator for Matrix Print*/
    friend std::ostream& operator<<(std::ostream& os, const Matrix33& matrix);

    /*Overload Operator for Matrix Input*/
    friend std::istream& operator>>(std::istream& in, Matrix33& matrix);

    int determinant(const Matrix33& matrixObject);

    private:
    int** Matrix;
};

#endif