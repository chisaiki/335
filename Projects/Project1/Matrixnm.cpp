#include "Matrixnm.h"

    Matrixnm::Matrixnm(){}

    Matrixnm::Matrixnm(int row, int column, int* existingArray) : rowN_(row), columnM_(column) 
    {
        if (row <= 0 || column <= 0 || existingArray == nullptr) {
            throw std::invalid_argument("Invalid matrix dimensions or null array.");
        }
        
        /*Initialize the 2D vector*/
        Matrix.resize(rowN_, std::vector<int>(columnM_));
        
        /*Copy data*/
        for (int i = 0; i < rowN_; i++) {
            for (int j = 0; j < columnM_; j++) {
                Matrix[i][j] = existingArray[i * columnM_ + j];
            }
        }
    }

     /*Copy Constructor*/
     Matrixnm::Matrixnm(const Matrixnm& other) : rowN_(other.rowN_), columnM_(other.columnM_)
     {
        /*Input Validation Check*/
        if (other.rowN_ <= 0 || other.columnM_ <= 0) 
        {
            throw std::invalid_argument("Invalid matrix dimensions.");
        }

        /*Simply copy the vector - it handles deep copying automatically*/
        Matrix = other.Matrix;
    }
    

    /*Move Constructor*/
    Matrixnm::Matrixnm(Matrixnm&& other) 
    {
        std::cout << "\nMove Constructor Called" << std::endl;
        
        rowN_ = other.rowN_;
        columnM_ = other.columnM_;
        Matrix = std::move(other.Matrix);
        
        other.rowN_ = 0;
        other.columnM_ = 0;
    }
    
    /*Copy Assignment Operator*/
    Matrixnm& Matrixnm::operator=(const Matrixnm& otherObject)
    {
        std::cout << "\nCopy Assignment Operator Called" << std::endl;
        
        if (this != &otherObject) 
        {
            
            if (otherObject.rowN_ <= 0 || otherObject.columnM_ <= 0) 
            {
                throw std::invalid_argument("Invalid matrix dimensions.");
            }
            
            
            rowN_ = otherObject.rowN_;
            columnM_ = otherObject.columnM_;
            
            /*Copy the matrix data (vector handles deep copying automatically)*/
            Matrix = otherObject.Matrix;
        }
        
        return *this;  /*Return reference to this object*/
    }

    /*Move Assignment Operator*/
    Matrixnm& Matrixnm::operator=(Matrixnm&& otherObject) 
    {
        std::cout << "\nMove Assignment Operator Called" << std::endl;
        
        if (this != &otherObject) 
        {
            /*Move the data (no need to validate - we're taking ownership)*/
            rowN_ = otherObject.rowN_;
            columnM_ = otherObject.columnM_;
            Matrix = std::move(otherObject.Matrix);
            
            /* Reset the moved-from object */
            otherObject.rowN_ = 0;
            otherObject.columnM_ = 0;
        }
        return *this;
    }

    /*Overload Operator for Matrix Multiplication*/

    /*Overload Operator for Scalar Multiplication*/

    /*Overload Operator for Matrix Addition*/

    // Matrixnm Matrixnm::operator*(const Matrixnm& other) const{}

    // int& Matrixnm::operator()(int row, int column) const{}

    /*Overload Operator for Matrix Print*/
    std::ostream& operator<<(std::ostream& os, const Matrixnm& matrix) {
        for (int i = 0; i < matrix.rowN_; i++) 
        {
            for (int j = 0; j < matrix.columnM_; j++) 
            {
                os << matrix.Matrix[i][j];
                if (j < matrix.columnM_ - 1) 
                {
                    /*needed to add spaces between matrix elements in the same row for proper formatting.*/
                    os << " ";
                }
            }
            if (i < matrix.rowN_ - 1) 
            {
                /*to output newlines*/
                os << std::endl;
            }
        }
        return os;
    }
    
    /*Overload Operator for Matrix Input*/
    std::istream& operator>>(std::istream& in, Matrixnm& matrix)
    {
        std::cout << "Please enter " << matrix.rowN_ * matrix.columnM_ << " integers: ";
    
        for (int i = 0; i < matrix.rowN_; i++) 
        {
            for (int j = 0; j < matrix.columnM_; j++) 
            {
                in >> matrix.Matrix[i][j];
            }
        }
        return in;
    }

    int Matrixnm::determinant(const Matrixnm& matrixObject)
    {
        if (matrixObject.rowN_ != matrixObject.columnM_)
        {
            std::cout << "Cannot compute determinant" << std::endl;
            return 0;
        }

        
    }
