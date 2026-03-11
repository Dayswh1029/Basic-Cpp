
/*
Matrix.h simple Matrix class 

*/

#ifndef _MATRIX_H
#define _MATRIX_H
#include<stdio.h>
#include<stdbool.h> // for bool

typedef struct  Matrix_
{
    size_t rows;
    size_t cols;
    float * data;
} Matrix;

// 函数的声明；

Matrix* createMatrix(size_t rows, size_t cols); //  创建一个 Matrix *

bool releaseMatrix(Matrix* ptr); // 释放内存 

bool add(const Matrix* input1, const Matrix* input2, Matrix* output );

#endif