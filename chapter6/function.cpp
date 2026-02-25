#include<iostream>
#include<float.h>

struct Matrix{
    size_t rows;
    size_t cols;

    float* pData;
    ~Matrix()
    {
        if(pData!=nullptr)
        {
            delete[] this->pData;
            pData=nullptr;
        }

    }

};

float matrix_max(const Matrix& mat)
{
    float max=FLT_MIN;
    for(size_t r=0;r<mat.rows;r++)
    {
        for(size_t c=0;c<mat.cols;c++)
        {
            float val=mat.pData[r*mat.cols+c];
            max=(max>val? max:val);
        }
    }
    return max;

}
int main()
{

    
    Matrix matA={3,4}; // 3rows  and  4cols 
    matA.pData= new float[matA.rows*matA.cols]{1.0f,2.0f,3.0f}; // 其余用零补充！


    Matrix matB={4,8};
    matB.pData= new float[matB.rows*matB.cols]{10.0f,20.0f,30.0f};


    Matrix matC={4,2};
    matC.pData= new float[matC.rows*matC.cols]{100.0f,200.0f,300.0f};

    //调用函数
    float maxa = matrix_max(matA);
    float maxb = matrix_max(matB);
    float maxc = matrix_max(matC);





    return 0;
}