#include "Matrixnm.h"

    Matrixnm::Matrixnm(){}

    Matrixnm::Matrixnm(int row, int column, int* existingArray) : rowN_(row), columnM_(column)
    {
        /*Input Validation Check*/
        if (row <= 0 || column <= 0 || existingArray == nullptr) 
        {
            throw std::invalid_argument("Invalid matrix dimensions or null array.");
        }
        
        Matrix = new int*[rowN_];
        for (int i = 0; i < rowN_; i++) 
        {
            Matrix[i] = new int[columnM_];
            for (int j = 0; j < columnM_; j++) 
            {
                Matrix[i][j] = existingArray[i * columnM_ + j]; /*row-major order formula for converting 2D coordinates to 1D array indices!*/
            }
        }
    }

     /*Copy Constructor*/
     Matrixnm::Matrixnm(const Matrixnm& other)
     {
        /*Input Validation Check*/
        if (other.rowN_ <= 0 || other.columnM_ <= 0) 
        {
            throw std::invalid_argument("Invalid matrix dimensions or null array.");
        }

        this->rowN_ = other.rowN_;
        this->columnM_ = other.columnM_;

        Matrix = new int*[rowN_];
        for (int i = 0; i < rowN_; i++) 
        {
            Matrix[i] = new int[columnM_];
            for (int j = 0; j < columnM_; j++) 
            {
                Matrix[i][j] = other.Matrix[i][j];
            }
        }
    }
    

    // /*Move Constructor*/
    // Matrixnm::Matrixnm(Matrixnm&& other){}
    
    // /*Copy Assignment Operator*/
    // Matrixnm& Matrixnm::operator=(const Matrixnm& otherObject){}

    // /*Move Assignment Operator*/
    // Matrixnm& Matrixnm::operator=(Matrixnm&& otherObject){}

    // /*Overload Operator for Matrix Multiplication*/
    // Matrixnm Matrixnm::operator*(const Matrixnm& other) const{}

    // int& Matrixnm::operator()(int row, int column) const{}

    /*Overload Operator for Matrix Print*/
    std::ostream& operator<<(std::ostream& os, const Matrixnm& matrix)
    {

        for (int i = 0; i < matrix.rowN_; i++) {
            for (int j = 0; j < matrix.columnM_; j++) {
                os << matrix.Matrix[i][j];
                if (j < matrix.columnM_ - 1) {
                    os << " ";
                }
            }
            if (i < matrix.rowN_ - 1) {
                os << std::endl;
            }
        }
        return os;
    }
    

    // /*Overload Operator for Matrix Input*/
    // std::istream& operator>>(std::istream& in, Matrixnm& matrix){}

    // int Matrixnm::determinant(const Matrixnm& matrixObject){}
