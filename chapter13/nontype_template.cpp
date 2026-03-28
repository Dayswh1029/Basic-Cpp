#include<iostream>

// non-type parameters  
// class  template 

template<typename T, size_t _rows, size_t _cols>
class Mat{
    T data[_rows][_cols];
    public:
        Mat(){}

        T getElement(size_t r, size_t c);
        bool setElement(size_t r, size_t c, T value);


};

template<typename T, size_t _rows, size_t _cols>
T Mat<T ,_rows,_cols>::getElement(size_t r, size_t c)
{
    if(r>=_rows||c>=_cols)
    {
        std::cerr<<"getElement(): indices are out of range"<<std::endl;
        return 0;
    }
    return data[r][c];
}

template<typename T, size_t _rows, size_t _cols>
bool Mat<T ,_rows,_cols>::setElement(size_t r, size_t c, T value)
{
    if(r>=_rows || c>=_cols)
    {
        std::cerr<<"setElement(): Indices are out of range"<<std::endl;
        return false;
    
    }
    data[r][c]=value;
    return true;
}




// 1. 显式实例化（如果需要），放在外面
template class Mat<int, 2, 2>;

template class Mat<float, 3,1>;
typedef Mat<int, 2,2>Mat22i;
typedef Mat<float, 3,1>vec;

int main()
{

    //template class Mat<int , 2,2>;

   // Mat<int ,2,2>;

    
    Mat22i mat;
    mat.setElement(2,3,256);

    std::cout<<mat.getElement(2,3)<<std::endl;

    mat.setElement(1,1,200);

    std::cout<<mat.getElement(1,1)<<std::endl;
    vec v;
    v.setElement(2,0,3.14159f);
    std::cout<<v.getElement(2,0)<<std::endl;

    vec v2(v); //

    std::cout<<v2.getElement(2,0)<<std::endl;















    return 0;
}