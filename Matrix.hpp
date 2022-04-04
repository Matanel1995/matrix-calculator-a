#include <iostream>
#include <string>
#include <vector>
using namespace std;
namespace zich{
    class Matrix{
        private:
            int row;
            int col;
            vector <double> matrix;
        public:
            Matrix(vector<double> matrix, int row, int col);
            ~Matrix(); // defult destractor

            //Plus operators
            Matrix operator + (const Matrix&mat);
            Matrix operator += (const Matrix&mat1);
            Matrix operator + ();
            Matrix operator ++ ();


            //Minus operators
            Matrix operator - (const Matrix&mat);
            Matrix  operator -= (const Matrix&mat1);
            Matrix operator - ();
            Matrix operator -- ();

            //Multiplaction operators
            Matrix operator * (const Matrix&mat);
            Matrix operator * (double num);
            Matrix operator *= (int scalar);
            friend Matrix operator * (const int& num, const Matrix& mat);

            //Comperations operators
            int operator > (const Matrix&mat1);
            int operator >= (const Matrix&mat1);
            int operator < (const Matrix&mat1);
            int operator <= (const Matrix&mat1);
            bool operator != (const Matrix&mat1);
            bool operator == (Matrix const & mat1);

            //Input and Output operators
            friend ostream& operator << (ostream &out ,Matrix const &matrix);

            //Getters functions
            int getRows() const {return this->row; }
            int getCols() const {return this->col; }
            vector<double> getMatrix() const {return this->matrix; }

            //input check
            friend bool isGood(const Matrix &mat);
    };
}