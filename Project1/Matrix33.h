class Matrix33
{
private: 

    int** matrix_ptr;

public:

    Matrix33(); /*Default Constructor*/
    Matrix33(int& matrixArray); 

    /*Copy Constructor*/
    matrix33Copy (const Matrix33& previousMatrixObject);

};
