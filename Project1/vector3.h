class Matrix33
{
private: 
    double x_;
    double y_;
    double z_;

    int* matrix_ptr = new matrix[3][3];

public:
    Matrix33(){};
    Matrix33(double x=0, double y=0, double z=0): x_(x), y_(y), z_(z){}

    Matrix33 operator+(Matrix33& other);
    Matrix33 operator*(double scalar);
    Matrix33 operator/(double scalar);
    bool operator==(Matrix33& other);
    double& operator()(int row);

    friend std::ostream& operator<<(std::ostream& out,const Matrix33& p);
    friend std::istream& operator>>(std::istream& in, Matrix33& p);
    
    double magnitude();

};
