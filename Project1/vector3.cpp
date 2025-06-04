#include <iostream>
#include <cmath>
#include "Matrix33.h"

using namespace std;

Matrix33 Matrix33::operator+(Matrix33& other)
{
    return Matrix33(x_+other.x_,y_+other.y_,z_+other.z_);
}


Matrix33 Matrix33::operator-(Matrix33& other)
{
    return Matrix33(x_-other.x_,y_-other.y_,z_-other.z_);
}


Matrix33 Matrix33::operator*(double scalar)
{
    return Matrix33(x_*scalar,y_*scalar,z_*scalar);
}


Matrix33 Matrix33::operator/(double scalar)
{
    return Matrix33(x_/scalar,y_/scalar,z_/scalar);
}


bool Matrix33::operator==(Matrix33& other)
{
    return x_==other.x_ && y_==other.y_ && z_==other.z_;
}


double Matrix33::magnitude()
{
    return sqrt(pow(x_,2)+pow(y_,2)+pow(z_,2));
}


ostream& operator<<(ostream& out,const Matrix33& p)
{
    out<<"("<<p.x_<<", "<<p.y_<<", "<<p.z_<<")"<<endl;
    return out;
}


istream& operator>>(istream& in, Matrix33& p)
{
    cout<<"Enter a Point(x,y,z): "<<endl;
    in>>p.x_>>p.y_>>p.z_;
    return in;
}


double& Matrix33::operator()(int row)
{
    if(row <= 0) return x_;
    else if(row == 1) return y_;
    else return z_;
}
