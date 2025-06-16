#include <iostream>
#include <vector>
#include "Matrix33.h"
#include "vector3.h"

std::vector<Vector3> getAx(const Matrix33& matrixObject, Vector3& vectorObject);

int main()
{
    int emptyInitialization[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    
    Matrix33 userMatrix(emptyInitialization);
    std::cin >> userMatrix;
    
    std::cout << userMatrix.determinant(userMatrix) << std::endl;

    Vector3 userVector;
    std::cin >> userVector;
   
    std::vector<Vector3> result = getAx(userMatrix, userVector);
    for (const auto& vector : result) {
        std::cout << std::endl << vector << std::endl; 
    }

}

std::vector<Vector3> getAx(const Matrix33& matrixObject, Vector3& vectorObject)
{
    std::vector<Vector3> b(3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            b[i] += (matrixObject(i, j) * vectorObject(i));
        }
    }

    return b;
}
