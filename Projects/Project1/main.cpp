#include <iostream>
#include <vector>
//#include "Matrix33.h"
#include "Matrixnm.h"
#include "vector3.h"

// std::vector<Vector3> getAx(const Matrix33& matrixObject, Vector3& vectorObject);

int main()
{
    int emptyInitialization[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    
    // Matrix33 userMatrix(emptyInitialization);
    // std::cin >> userMatrix;
    
    // std::cout << "The Determinant is: " << userMatrix.determinant(userMatrix) << std::endl;

    // Vector3 userVector;
    // std::cin >> userVector;
   
    // std::vector<Vector3> result = getAx(userMatrix, userVector);
    // for (const auto& vector : result) {
    //     std::cout << std::endl << vector << std::endl; 
    //}
    
    int array[4][5] = {{1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}, {16,17,18,19,20}};

    Matrixnm matrix(4, 5, (int*)array);
    std::cout << matrix << std::endl;

    Matrixnm copyMatrix(matrix);
    std::cout << copyMatrix;

}

// std::vector<Vector3> getAx(const Matrix33& matrixObject, Vector3& vectorObject)
// {
//     std::vector<Vector3> b(3);
//     for (int i = 0; i < 3; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             b[i] += (matrixObject(i, j) * vectorObject(i));
//         }
//     }

//     return b;
// }
