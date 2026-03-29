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


// non-type template parameter 

template<typename T, size_t size>
class Mat2
{
    private: 
        T arr[size]; // automatic array  initialization 
    public:
        void insert()
        {
            int i=1;
            for(int j=0;j<size;j++)
            {
                arr[j]=i;
                i++;
            }
        }
        void display()
        {
            for(int i=0;i<size;i++)
            {
                std::cout<<arr[i]<<" ";
            }
            std::cout<<std::endl;
        }

};

// numtiple  parameters 

template <typename T1, typename T2>
class A
{
    private:
        T1 a;
        T2 b;
    public:
        A(T1 x,T2 y):a(x),b(y)
        {

        }
        void display()
        {
            std::cout<<"values of a and b are: "<<a<<" ,"<<b<<std::endl;

        }

};



// multiple and  default parameters
template<typename T,typename U, typename V=char>
class MultipleParameters
{
    private:
        T var1;
        U var2;
        V var3;

    public:
        MultipleParameters(T v1, U v2, V v3):var1(v1),var2(v2),var3(v3){}

        void printVar()
        {
            std::cout<<"var1 = "<<var1<<std::endl;
            std::cout<<"var2 = "<<var2<<std::endl;
            std::cout<<"var3 = "<<var3<<std::endl;
        }


};




















#endif  // MATRIX_H