#include "doctest.h"
#include "Matrix.hpp"
#include <stdexcept>
#include <vector>

using namespace zich;
using namespace std;


TEST_CASE("check throws"){
    const vector<double> vector1 = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0};
    bool ans;
    Matrix matrix1(vector1,3,4); // 3X4 matrix
    Matrix matrix2(vector1,4,3); // 4X3 matrix
    CHECK_THROWS(matrix1 + matrix2);
    CHECK_THROWS(matrix1 += matrix2);
    CHECK_THROWS(matrix1 - matrix2);
    CHECK_THROWS(matrix1 -= matrix2);
    CHECK_NOTHROW(matrix1 * matrix2);
    CHECK_THROWS(matrix2 * matrix1);
    CHECK_THROWS(ans = (matrix2 == matrix1));
    CHECK_THROWS(ans = (matrix2 != matrix1));
    CHECK_THROWS(ans = (matrix2 < matrix1));
    CHECK_THROWS(ans = (matrix2 > matrix1));
    CHECK_THROWS(ans = (matrix2 <= matrix1));
    CHECK_THROWS(ans = (matrix2 >= matrix1));
    }

TEST_CASE("Check functions output"){
    const vector<double> vector1 = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0};
    Matrix matrix1(vector1,3,4); // 3X4 matrix
    Matrix matrix2(vector1,3,4); // 4X3 matrix
    //CHECK COMPARATIONS OPERATORS
    bool ans = true;
    bool ans1;
    ans1 = matrix1 == matrix2;
    CHECK(ans == ans1);
    ans1 = matrix1 >= matrix2;
    CHECK(ans == ans1);
    ans1 = matrix1 <= matrix2;
    CHECK(ans == ans1);
    ans = false;
    ans1 = matrix1 != matrix2;
    CHECK(ans == ans1);
    ans1 = matrix1 > matrix2;
    CHECK(ans == ans1);
    ans1 = matrix1 < matrix2;
    CHECK(ans == ans1);

    //CHECK PLUS FUNCTIONS
    const vector<double> vector2 = {5, 4, 4, 4, 4, 5, 4, 4, 4, 4, 5, 4};
    Matrix matrixUnariPlus(vector2,3,4); // 3X4 matrix
    ans = true;
    const vector<double> toAdd = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    const vector<double> vectorAnsAdd = {2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1};
    Matrix matrixTemp(toAdd,3,4);
    Matrix matrixAnsAdd(vectorAnsAdd,3,4);
    ans1 = (matrixAnsAdd == matrix1 + matrixTemp); 
    CHECK(ans == ans1);
    ans1 = (matrixAnsAdd != ++matrix1);
    CHECK(ans == ans1);
    ans1 = (matrixAnsAdd == ++matrix1);
    CHECK(ans == ans1);

    //CHECK MINUS FUNCTIONS
    const vector<double> toSub = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    const vector<double> vectorAnsSub = {0, -1, -1, -1, -1, 0, -1, -1, -1, -1, 0, -1};
    const vector<double> vector2Sub = {-4, -5, -5, -5, -5, -4, -5, -5, -5, -5, -4, -5};
    Matrix matrixTempSub(toSub,3,4);
    Matrix matrixAnsSub(vectorAnsSub,3,4);
    Matrix matrixUnariMinus(vector2Sub,3,4); // 3X4 matrix
    ans1 =(matrixAnsSub == matrix1 - matrixTempSub);
    CHECK(ans == ans1);
    ans1 =(matrixAnsSub != --matrix1);
    CHECK(ans == ans1);
    ans1 =(matrixAnsSub == --matrix1);
    CHECK(ans == ans1);

    //CHECK MULT FUNCTIONS
    const vector<double> identity = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    const vector<double> vectorAnsMul = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
    const vector<double> vectorAnsMul2Mat = {15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15};
    Matrix matrixTempMul(identity,3,4);
    Matrix matrixTempMul2(vectorAnsMul,4,3);
    Matrix matrixAnsMul(vectorAnsMul,3,4);
    Matrix matrixAnsMul2Mat(vectorAnsMul2Mat,4,4);
    ans1 = (matrixAnsMul == 5 * matrixTempMul);
    CHECK(ans == ans1);
    ans1 = (matrixAnsMul2Mat == matrixTempMul2 * matrixTempMul);
    CHECK(ans == ans1);
}