#ifndef MATRIX_H
#define MATRIX_H

#pragma once
#include<iostream>
//#define MAXSIZE 5
const int MAXSIZE =5; // 现代C++ 
template <typename T>
class Mat{
    private:
        T matrix[MAXSIZE];
        size_t size;
    public:
        Mat();
        ~Mat(){}
        void printMat();
        void setMat(T[]); // 接受的是 T 类型的数组！ 
        void addMat(T[]); // 完成 add 加法！

};
template<typename T>
Mat<T>::Mat():size(MAXSIZE)
{

}
template<typename T>
void Mat<T>::printMat()
{
    for(size_t i=0;i<size;i++)
        std::cout<<matrix[i]<<" ";
    std::cout<<"\n";
    
}
template<typename T>
void Mat<T>::setMat(T array[])
{
    for(size_t i=0;i<size;i++)
        matrix[i]=array[i];

}
template<typename T>
void Mat<T>::addMat(T otherArray[])
{
    for(size_t i=0;i<size;i++)
        matrix[i]+=otherArray[i];

}


#endif  // MATRIX_H