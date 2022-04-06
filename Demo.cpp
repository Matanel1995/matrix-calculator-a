/**
 * Demo file for the exercise on numbers with units
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 * 
 * Edited by Tal Zichlinsky
 * @since 2022-02
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "Matrix.hpp"
using namespace zich;

int main() {
  
  std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
  std::vector<double> arr = {3, 0, 0, 0, 3, 0, 0, 0, 3};
  Matrix a{identity, 3, 3};  // constructor taking a vector and a matrix size
  //cout << a << " first line " << endl;
  /* prints [1 0 0]
            [0 1 0]
            [0 0 1]*/
  //cout << (-a) << " second line " << endl;
  /* prints [-1 0 0]
            [0 -1 0]
            [0 0 -1]*/
  //cout << (a*3) << " third line " << endl;
  //cout << (a*-3) << " third line " << endl;
  cout << "**************************************" << endl;
  cout << "REgular matrix \n" << a << endl;
  cout << " A++ \n" << (a++) <<  endl;
  cout << " ++A \n" << (++a) <<  endl;
  cout << " A++ \n" << (a--) <<  endl;
  cout << " ++A \n" << (--a) <<  endl;
  //cout << "**************************************" << endl;
  /* prints [3 0 0]
            [0 3 0]
            [0 0 3]*/

  Matrix b{arr, 3, 3};
  //cout << (a > b) << " third line " << endl;
  //cout << (a < b) << " third line " << endl;
  //a *= -3;
  //cout << (a+b) << " forth line " << endl;  // prints the 0 matrix
  //cout << (b-a) << " fifth line " << endl;
  /* prints [6 0 0]
            [0 6 0]
            [0 0 6]*/

  cout << "End of demo!" << endl;
  return 0;
}
