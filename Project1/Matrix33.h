#ifndef _MATRIX33_H
#define _MATRIX33_H

class Matrix33
{
    public:
    void printFunc();

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

    private:
    int** Matrix;
};

#endif