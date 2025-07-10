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
    Matrixnm Matrixnm::operator*(const Matrixnm& other) const
    {
        /*the number of columns in the first matrix must equal the number of rows in the second matrix*/
        if(this->columnM_ != other.rowN_)  
        {
            throw std::invalid_argument("Matrix dimensions incompatible for multiplication.");
        }

        /*The resulting matrix will have dimensions: this->rowN_ x other.columnM_*/
        Matrixnm result;
        result.rowN_ = this->rowN_;
        result.columnM_ = other.columnM_; 
        result.Matrix.resize(result.rowN_, std::vector<int>(result.columnM_, 0)); 

        /*Matrix multiplication: result[i][j] = sum(this[i][k] * other[k][j])*/
        for(int i = 0; i < this->rowN_; i++)
        {
            for(int j = 0; j < other.columnM_; j++) /*iterate through other's columns*/
            {
                result.Matrix[i][j] = 0; 
                for(int k = 0; k < this->columnM_; k++)  
                {
                    result.Matrix[i][j] += this->Matrix[i][k] * other.Matrix[k][j];
                }
            }
        }

        return result;
    }

    /*Overload Operator for Scalar Multiplication*/
    Matrixnm Matrixnm::operator*(int scalar) const
    {
        Matrixnm result;
        /*Make sure result matrix is the same dimensions*/
        result.rowN_ = this->rowN_;
        result.columnM_ = this->columnM_;
        result.Matrix.resize(rowN_, std::vector<int>(columnM_));

        for(int i = 0; i < this->rowN_; i++)
        {
            for(int j = 0; j < this->columnM_; j++)
            {
                result.Matrix[i][j] = Matrix[i][j] * scalar;
            }
        }

        return result;
    }

    /*Overload + operator for matrix addition*/
    Matrixnm Matrixnm::operator+(const Matrixnm& other) const
    {
        /*matrix addition is only defined when the matrices are of the same size.*/
        if(this->columnM_ != other.columnM_ || this->rowN_ != other.rowN_)
        {
            throw std::invalid_argument("Addition not possible.");
        }

        Matrixnm result;
        /*Make sure result matrix is the same dimensions*/
        result.rowN_ = this->rowN_;
        result.columnM_ = this->columnM_;
        result.Matrix.resize(rowN_, std::vector<int>(columnM_));

        for(int i = 0; i < this->rowN_; i++)
        {
            for(int j = 0; j < this->columnM_; j++)
            {
                result.Matrix[i][j] = Matrix[i][j] + other.Matrix[i][j];
            }
        }

        return result;
    }

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
            throw std::invalid_argument("Determinant only defined for square matrices.");
        }
        
        int n = matrixObject.rowN_;
        
        /*Base cases*/
        if (n == 1) {
            return matrixObject.Matrix[0][0];
        }
        
        if (n == 2) {
            return matrixObject.Matrix[0][0] * matrixObject.Matrix[1][1] - 
                   matrixObject.Matrix[0][1] * matrixObject.Matrix[1][0];
        }
        
        /*For larger matrices, use cofactor expansion along first row*/
        int det = 0;
        for (int j = 0; j < n; j++) {
            /*Create minor matrix*/
            Matrixnm minor;
            minor.rowN_ = n - 1;
            minor.columnM_ = n - 1;
            minor.Matrix.resize(n - 1, std::vector<int>(n - 1));
            
            /*Fill minor matrix*/
            for (int i = 1; i < n; i++) {
                for (int k = 0; k < n; k++) {
                    if (k < j) {
                        minor.Matrix[i-1][k] = matrixObject.Matrix[i][k];
                    } else if (k > j) {
                        minor.Matrix[i-1][k-1] = matrixObject.Matrix[i][k];
                    }
                }
            }
            
            /*Add cofactor to determinant*/
            int cofactor = ((j % 2 == 0) ? 1 : -1) * matrixObject.Matrix[0][j] * determinant(minor);
            det += cofactor;
        }
        
        return det;
    }
