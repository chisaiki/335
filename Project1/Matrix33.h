class Matrix33
{
private: 

    int** matrix_ptr;

public:

    Matrix33(); /*Default Constructor*/
    Matrix33(int& matrixArray); 

    /*Copy Constructor*/
    Matrix33 (const Matrix33& previousMatrixObject);

};
