#include "Matrix33.h"
#include <iostream>

/*Default Constructor*/
Matrix33::Matrix33(){}

/*Constructor that accepts a 2D Array*/
Matrix33::Matrix33(int matrixArray[3][3])
{
    Matrix = new int*[3];
    for (int i = 0; i < 3; ++i) 
    {
        Matrix[i] = new int[3];
        for (int j = 0; j < 3; ++j) 
        {
            Matrix[i][j] = matrixArray[i][j];
        }
    }
}

/*Copy Constructor*/
Matrix33::Matrix33(const Matrix33& other)
{
    std::cout << "\nCopy Constructor Called" << std::endl;
        
    Matrix = new int*[3];
    for (int i = 0; i < 3; ++i) 
    {
        Matrix[i] = new int[3];
        for (int j = 0; j < 3; ++j) 
        {
            Matrix[i][j] = other.Matrix[i][j];
        }
    }
}

/*Move Constructor*/
Matrix33::Matrix33(Matrix33&& other)
{
    std::cout << "\nMove Constructor Called" << std::endl;
    Matrix = other.Matrix;
    other.Matrix = nullptr;
}

/*Copy Assignment Operator*/
Matrix33& Matrix33::operator=(const Matrix33& otherObject)
{
    std::cout << "\nCopy Assignment Operator Called" << std::endl;

    if (this != &otherObject) 
    {
        /*Free existing memory*/
        for (int i = 0; i < 3; ++i)
            delete[] Matrix[i];
        delete[] Matrix;

        /* Allocate new memory and copy */
        Matrix = new int*[3];
        for (int i = 0; i < 3; ++i) 
        {
            Matrix[i] = new int[3];
            for (int j = 0; j < 3; ++j) {
                Matrix[i][j] = otherObject.Matrix[i][j];
            }
        }
    }
    return *this;
}

/*Move Assignment Operator*/
Matrix33& Matrix33::operator=(Matrix33&& otherObject)
{
    std::cout << "\nMove Assignment Operator Called" << std::endl;

    if (this != &otherObject) 
    {
        /*Free existing memory*/
        for (int i = 0; i < 3; ++i)
            delete[] Matrix[i];
        delete[] Matrix;

        Matrix = otherObject.Matrix;
        otherObject.Matrix = nullptr;
    }
    return *this;
}

/*Overload Operator for Matrix Multiplication*/
Matrix33 Matrix33::operator*(const Matrix33& other) const
{
    int resultArray[3][3] = {0};
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            for (int k = 0; k < 3; k++) 
            /*Performs the sum of products for each element*/
            {
                resultArray[i][j] += Matrix[i][k] * other.Matrix[k][j];
            }
        }
    }
    return Matrix33(resultArray);
}

/*Overload * operator for scalar multiplication*/
Matrix33 Matrix33::operator*(int scalar) const
{
    int resultArray[3][3] = {0};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            resultArray[i][j] = Matrix[i][j] * scalar;
        }
    }

    return Matrix33(resultArray);
}

/*Overload + operator for matrix addition*/
Matrix33 Matrix33::operator+(const Matrix33& other) const
{
    int resultArray[3][3] = {0};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            resultArray[i][j] = Matrix[i][j] + other.Matrix[i][j];
        }
    }

    return Matrix33(resultArray);
}

int& Matrix33::operator()(int row, int column) const
{
    return Matrix[row][column];
}

/*Overload Operator for Matrix Print*/
std::ostream& operator<<(std::ostream& os, const Matrix33& matrix)
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            os << matrix.Matrix[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}

/*Overload Operator for Matrix Input*/
std::istream& operator>>(std::istream& in, Matrix33& matrix)
{
    std::cout << "Please enter 9 consecutive integers: "; 
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            in >> matrix.Matrix[i][j];
        }
    }
    return in;
}

int Matrix33::determinant(const Matrix33& matrixObject)
{
    int determinant = ((matrixObject.Matrix[0][0] * matrixObject.Matrix[1][1] * matrixObject.Matrix[2][2]) + (matrixObject.Matrix[0][1] * matrixObject.Matrix[1][2] * matrixObject.Matrix[2][0]) + (matrixObject.Matrix[0][2] * matrixObject.Matrix[1][0] * matrixObject.Matrix[2][1]) - (matrixObject.Matrix[0][2] * matrixObject.Matrix[1][1] * matrixObject.Matrix[2][0]) - (matrixObject.Matrix[0][0] * matrixObject.Matrix[1][2] * matrixObject.Matrix[2][1])  - (matrixObject.Matrix[0][1] * matrixObject.Matrix[1][0] * matrixObject.Matrix[2][2]));
    return determinant;
}
