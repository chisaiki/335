#ifndef _MATRIX33_H
#define _MATRIX33_H

#include <iostream>
#include <vector>  


class Matrixnm
{
    private:
    int rowN_, columnM_;
    std::vector<std::vector<int>> Matrix; 

    public:
    /*Default Constructor*/
    Matrixnm();
    Matrixnm(int row, int column, int* existingArray);

    /*Copy Constructor*/
    Matrixnm(const Matrixnm& other);
    
    /*Move Constructor*/
    Matrixnm(Matrixnm&& other);
    
    /*Copy Assignment Operator*/
    Matrixnm& operator=(const Matrixnm& otherObject);

    /*Move Assignment Operator*/
    Matrixnm& operator=(Matrixnm&& otherObject);

    /*Overload Operator for Matrix Multiplication*/
    Matrixnm operator*(const Matrixnm& other) const;

    /*Overload * operator for scalar multiplication*/
    Matrixnm operator*(int scalar) const;

    /*Overload + operator for matrix addition*/
    Matrixnm operator+(const Matrixnm& other) const;

    /*Overload Operator for Matrix Print*/
    friend std::ostream& operator<<(std::ostream& os, const Matrixnm& matrix);

    /*Overload Operator for Matrix Input*/
    friend std::istream& operator>>(std::istream& in, Matrixnm& matrix);

    int determinant(const Matrixnm& matrixObject);
};

#endif

