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

     /*Test Matrix Addition - Create two valid matrices*/
    int array1[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int array2[2][3] = {{7, 8, 9}, {10, 11, 12}};
    int array3[3][2] = {{7, 8}, {9, 10}, {11, 12}};
    
    Matrixnm matrix1(2, 3, (int*)array1);
    Matrixnm matrix2(2, 3, (int*)array2);
    Matrixnm matrix3(3, 2, (int*)array3);
    
    std::cout << "Matrix 1:\n" << matrix1 << std::endl;
    std::cout << "Matrix 2:\n" << matrix2 << std::endl;
    
    // Test matrix addition
    Matrixnm addResult = matrix1 + matrix3;
    std::cout << "Matrix 1 + Matrix 2:\n" << addResult << std::endl;

    /*Column == Row*/
    Matrixnm multResult = matrix1 * matrix3;
    std::cout << "Matrix 1 * Matrix 2:\n" << multResult << std::endl;

    Matrixnm scalarResult = matrix1 * 3;
    std::cout << "Matrix 1 * 3:\n" << scalarResult << std::endl;


    
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
