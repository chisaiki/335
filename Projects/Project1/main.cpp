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

    std::vector<std::vector<int>> testMatrix = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20}
    };

    /*Why auto? auto deduces that 'row' is of type: std::vector<int>*/
    for (const auto& row : testMatrix) {
        for (int v : row) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }


    /*test copy constructor*/
    Matrixnm vector2(4, 5, (int*)array); 
    std::cout << vector2 << std::endl;

    Matrixnm vector3 = std::move(vector2);
    std::cout << vector3 << std::endl;
    std::cout << "VEC2" << vector2 << std::endl;

    
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
