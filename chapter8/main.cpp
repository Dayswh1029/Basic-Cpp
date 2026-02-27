#include<iostream>
#include<cstdlib>
#include<chrono>
#include"mat_operation.hpp"
#include"mat_operation.cpp"
// 时间写成宏的形式！
#define TIME_START  auto start_time=std::chrono::steady_clock::now();
#define TIME_END(NAME) \
             auto end_time=std::chrono::steady_clock::now();\
             auto duration=std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time).count(); \
             std::cout<<(NAME)<<": result="<<result \
                    <<", duration = "<<duration<<"ms"<<std::endl;


int main(int argc, char**argv)
{


    size_t nSize=200000000;
    float *p1= new float[nSize];
    float *p2= new float[nSize];


    //256bits aligned, C++17 standard
    // float *p1=static_cast<float*>(aligned_alloc(256,nSize*sizeof(float))); 

    // float *p2=static_cast<float*>(aligned_alloc(256,nSize*sizeof(float)));
// Example 
    float result=0.0f;
    p1[2]=2.3f;
    p2[2]=3.0f;
    p1[nSize-1]=2.0f;
    p2[nSize-1]=1.1f;

    // auto start =std::chrono::steady_clock::now();
    // auto end =std::chrono::steady_clock::now();
    // auto duration=0L;
    // 程序热身！
    result=dotproduct(p1,p2,nSize);
    result=dotproduct(p1,p2,nSize);

//1， normal
    // TIME_START
    // result=dotproduct(p1,p2,nSize);
    // TIME_END("normal")
    // 

//2， unloop   
    // TIME_START
    // result=dotproduct_unloop(p1,p2,nSize);
    // TIME_END("unloop")
//3, SIMD 必须前提是ARM 处理器
    // TIME_START
    // result=dotproduct_neon_omp(p1,p2,nSize);
    // TIME_END("SIMD")


//4，SIMD+OpenMP 
    TIME_START
    result=dotproduct_neon_omp(p1,p2,nSize);
    TIME_END("SIMD+OpenMP")


    // 删除 
    delete[] p1;
    delete[] p2;






    return 0;
}