#include <iostream>
#include <string>
#include "Matrix.hpp"
#include<vector>
using namespace zich;
using namespace std;

zich::Matrix::Matrix(vector<double> matrix, int row, int col){
    this->row = row;
    this->col = col;
    this->matrix = std::move(matrix);
}

zich::Matrix::~Matrix(){

}

//Plus operators
Matrix Matrix::operator + (const Matrix&mat){
    Matrix ans (this->matrix, this->row, this->col);
    return ans;
}
Matrix Matrix::operator += (const Matrix&mat1){
    Matrix ans (this->matrix, this->row, this->col);
    return ans;
}
Matrix Matrix::operator + (){
    Matrix ans (this->matrix, this->row, this->col);
    return ans;
}
Matrix Matrix::operator ++ (){
    Matrix ans (this->matrix, this->row, this->col);
    return ans;
}

//Minus operators
Matrix Matrix::operator - (const Matrix&mat){
    Matrix ans (this->matrix, this->row, this->col);
    return ans;
}
Matrix Matrix::operator -= (const Matrix&mat1){
    Matrix ans (this->matrix, this->row, this->col);
    return ans;
}
Matrix Matrix::operator - (){
    Matrix ans (this->matrix, this->row, this->col);
    return ans;
}
Matrix Matrix::operator -- (){
    Matrix ans (this->matrix, this->row, this->col);
    return ans;
}

//Multiplaction operators
Matrix Matrix::operator * (const Matrix&mat){
    Matrix ans (this->matrix, this->row, this->col);
    return ans;
}
Matrix Matrix:: operator * (double num){
    Matrix ans (this->matrix, this->row, this->col);
    return ans;
}
Matrix zich::operator * (const int& num, const Matrix& mat){
    return mat;
}
Matrix Matrix::operator *= (int scalar){Matrix ans (this->matrix, this->row, this->col);
    return ans;
    }

//Comperations operators
int Matrix::operator > (const Matrix&mat1){return 1;}
int Matrix::operator >= (const Matrix&mat1){return 1;}
int Matrix::operator < (const Matrix&mat1){return 1;}
int Matrix::operator <= (const Matrix&mat1){return 1;}
bool Matrix::operator != (const Matrix&mat1){return true;}
bool Matrix::operator == (const Matrix&mat1){return true;}

//Input and Output operators
ostream& zich::operator<<(ostream& out , const Matrix& matrix){
    // for(int i=0; i<matrix.getRows();i++){
    //     cout<< "[";
    //     for(int j=0;j<matrix.getCols();j++){
    //         out<< matrix[i][j] << " ";
    //     }
    //     out << "]" << endl;
    // }
    return out;
}

bool isGood(const Matrix &mat){
    return false;
}