
#ifndef OPERAT_FUNC_H_
#define OPERAT_FUNC_H_

#include "twodarray.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

bool edit(two2Darray &left);
void add (two2Darray &arr1, two2Darray &arr2, two2Darray &arrRes);
void subtract (two2Darray &arr1, two2Darray &arr2, two2Darray &arrRes);
void multiplyMatrices (two2Darray &arr1, two2Darray &arr2, two2Darray &arrRes);
void Gaussian_Elimination(two2Darray &arr, two2Darray &arrRes);
void invertMatrices(two2Darray &arr, two2Darray &arrRes);
void makeLeadingOnes(two2Darray &arr, two2Darray &arrRes, int rows, int pos);
void reduceLowerTriangular(two2Darray &arr, two2Darray &arrRes, int rows, int col, int pos);
/*
 * 1 n n
 * 0 1 n
 * 0 0 1
 */
void reduceUpperTriangular(two2Darray &arr, two2Darray &arrRes, int rows, int cols, int pos);
/*
 * 1 0 0
 * n 1 0
 * n n 1
 */
//Combined they will give
/*
 * 1 0 0
 * 0 1 0
 * 0 0 1
 */


#endif // OPERAT_FUNC_H_
