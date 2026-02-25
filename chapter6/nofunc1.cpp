#include<iostream>
#include<float.h>

struct Matrix
{
    size_t rows;
    size_t cols;
    float * pData;
    // 1. 构造函数
    Matrix(size_t r, size_t c) : rows(r), cols(c) {
        pData = new float[r * c];
    }
    // 2. 实现深拷贝 (拷贝构造函数)
    Matrix(const Matrix& other) {
        this->rows = other.rows;
        this->cols = other.cols;
        // 第一步：申请新内存
        this->pData = new float[rows * cols];
        // 第二步：复制数据
        for (size_t i = 0; i < rows * cols; ++i) {
            this->pData[i] = other.pData[i];
        }
        std::cout << "执行了深拷贝！" << std::endl;
    }


    ~Matrix()
    {
        delete[] this->pData; // 
        pData=nullptr; // 防止 野指针！ wild pointer
    }

};

int main()
{

    Matrix matA={3,4}; // 3rows  and  4cols 
    matA.pData= new float[matA.rows*matA.cols]{1.0f,2.0f,3.0f}; // 其余用零补充！


    Matrix matB={4,8};
    matB.pData= new float[matB.rows*matB.cols]{10.0f,20.0f,30.0f};


    Matrix matC={4,2};
    matC.pData= new float[matC.rows*matC.cols]{100.0f,200.0f,300.0f};


    //some operations on the matrices 

    float maxa=FLT_MIN; //最小的正浮点数！！
    float maxb=FLT_MIN;
    float maxc=FLT_MIN;

    //find max value of matA
    for(size_t r=0;r<matA.rows;r++)
    {
        for(size_t c=0;c<matA.cols;c++)
        {
            float val=matA.pData[r*matA.cols+c]; // 指针 可以当做 数组处理！
            maxa=(maxa>val? maxa:val);

        }
    }
    std::cout<<"maxa= "<<maxa<<std::endl;

    //find max value of matB
    for(size_t r=0;r<matB.rows;r++)
    {
        for(size_t c=0;c<matB.cols;c++)
        {
            float val=matB.pData[r*matB.cols+c]; // 指针 可以当做 数组处理！
            maxb=(maxb>val? maxb:val);

        }
    }
    std::cout<<"maxb= "<<maxb<<std::endl;

    //find max value of matC
    for(size_t r=0;r<matC.rows;r++)
    {
        for(size_t c=0;c<matC.cols;c++)
        {
            float val=matC.pData[r*matC.cols+c]; // 指针 可以当做 数组处理！
            maxc=(maxc>val? maxc:val);

        }
    }
    std::cout<<"maxc= "<<maxc<<std::endl;
    // 这就需要引入function！ 

    // delete 【】

    // delete[] matA.pData;
    // delete[] matB.pData;
    // delete[] matC.pData;
    
    //  我们需要深拷贝！
    //Matrix matd=matA;



    return 0;
}






