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
zich::Matrix::Matrix(const Matrix&mat){
    matrix = mat.matrix;
    row = mat.row;
    col = mat.col;
}

zich::Matrix::~Matrix(){}

//****************************************************************//
//Seters functions
void Matrix::setIndexAt(unsigned int pos , double value){
    if(pos < 0 || pos >= this->col*this->row){
        throw std::invalid_argument{"Index is out of range"};
    }
    else{
        this->matrix.at(pos) = value;
    }
}
//****************************************************************//

//****************************************************************//
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
    return *this;
}
Matrix Matrix::operator ++ (){
    for(int i=0; i < this->getRows() ; i++){
        for(int j = 0 ; j<this->getCols() ; j++){
            unsigned int index = (unsigned int)((i*this->getCols()) + j);
                this->setIndexAt(index , this->getAt(index) + 1);
        }
    }
    return *this;
}
Matrix Matrix::operator ++(int){
    Matrix returnedAns = *this;
    //cout << "After increament \n" << returnedAns << endl;
    for(int i=0; i < this->getRows() ; i++){
        for(int j = 0 ; j<this->getCols() ; j++){
            unsigned int index = (unsigned int)((i*this->getCols()) + j);
                this->setIndexAt(index , this->getAt(index) + 1);
        }
    }
    return returnedAns;
}
//****************************************************************//

//****************************************************************//
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
    for(int i=0; i < this->getRows() ; i++){
        for(int j = 0 ; j<this->getCols() ; j++){
            unsigned int index = (unsigned int)((i*this->getCols()) + j);
            if(this->getAt(index) != 0){
                this->setIndexAt(index , this->getAt(index)* -1);
            }
        }
    }
    return *this;
}
Matrix Matrix::operator -- (){
    for(int i=0; i < this->getRows() ; i++){
        for(int j = 0 ; j<this->getCols() ; j++){
            unsigned int index = (unsigned int)((i*this->getCols()) + j);
                this->setIndexAt(index , this->getAt(index) - 1);
        }
    }
    return *this;
}
Matrix Matrix::operator --(int){
    Matrix returnedAns = *this;
    for(int i=0; i < this->getRows() ; i++){
        for(int j = 0 ; j<this->getCols() ; j++){
            unsigned int index = (unsigned int)((i*this->getCols()) + j);
                this->setIndexAt(index , this->getAt(index) - 1);
        }
    }
    return returnedAns;
}
//****************************************************************//

//****************************************************************//
//Multiplaction operators
Matrix Matrix::operator * (const Matrix&mat){
    Matrix ans (this->matrix, this->row, this->col);
    return ans;
}
Matrix Matrix:: operator * (double num){
    for(int i=0; i < this->getRows() ; i++){
        for(int j = 0 ; j<this->getCols() ; j++){
            unsigned int index = (unsigned int)((i*this->getCols()) + j);
            if(this->getAt(index) != 0){
                this->setIndexAt(index , this->getAt(index)*num);
            }
        }
    }
    return *this;
}
Matrix Matrix:: operator * (int num){
    for(int i=0; i < this->getRows() ; i++){
        for(int j = 0 ; j<this->getCols() ; j++){
            unsigned int index = (unsigned int)((i*this->getCols()) + j);
            if(this->getAt(index) != 0){
                this->setIndexAt(index , this->getAt(index)*num);
            }
        }
    }
    return *this;
}
Matrix Matrix::operator *= (int scalar){
    return this->operator*(scalar);
    }
Matrix Matrix::operator *= (double scalar){
    return this->operator*(scalar);
}
//****************************************************************//

//****************************************************************//
//Comperations operators
bool Matrix::operator > (Matrix&mat1){
    if(this->CalcSum() > mat1.CalcSum()){
        return true;
    }
    return false;
}

bool Matrix::operator >= (Matrix&mat1){
    if(*this == mat1 || *this > mat1){
        return true;
    }
    return false;
    }

bool Matrix::operator < (Matrix&mat1){
    if(this->CalcSum() < mat1.CalcSum()){
        return true;
    }
    return false;
    }

bool Matrix::operator <= (Matrix&mat1){
    if(*this == mat1 || *this < mat1){
        return true;
    }
    return false;
}

bool Matrix::operator != (Matrix&mat1){
    return !this->operator==(mat1);
    }

bool Matrix::operator == (Matrix&mat1){
    if(this->isGood(mat1)){
        for(int i=0; i < this->getRows() ; i++){
            for(int j = 0 ; j<this->getCols() ; j++){
                unsigned int index = (unsigned int)((i*this->getCols()) + j);
                if(this->getAt(index) != mat1.getAt(index)){
                    return false;
                }
            }
        }
    }
    return true;
}
//****************************************************************//

//****************************************************************//
//Input and Output operators
ostream& zich::operator<<(ostream& out , const Matrix& matrix){
    for(int i=0; i<matrix.getRows();i++){
        cout<< "[";
        for(int j=0;j<matrix.getCols();j++){
            unsigned int index = (unsigned int)((i*matrix.getCols())+j);
            out << matrix.matrix.at(index) << " ";
        }
        out << "]" << endl;
    }
    return out;
}
//****************************************************************//

//****************************************************************//
// Function to check if i can make mathemtics opretaions with the given 2 matrix.
bool Matrix::isGood(const Matrix &mat){
    if(this->getCols() <0 || this->getRows() < 0 || this->getCols() != mat.getCols() || this->getRows() != mat.getRows()){
        throw std::logic_error{"The matrixes are NOT the same size!"};
    }
    else{
        return true;
    }
    return false;
}
//****************************************************************//

double Matrix::CalcSum(){
    double ans = 0;
    for(int i=0; i<this->getRows();i++){
        for(int j=0;j<this->getCols();j++){
            unsigned int index = (unsigned int)((i*this->getCols())+j);
            ans += this->getAt(index);
        }
    }
    return ans;
}