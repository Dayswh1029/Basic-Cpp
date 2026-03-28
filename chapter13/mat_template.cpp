#include<iostream>

// 采用 模版！ template 
template<typename T>
class Mat{
    private:
        size_t _rows;
        size_t _cols;
        T* _data;
    public:
        Mat():_rows(0),_cols(0),_data(nullptr)
        {

        }
        Mat(const size_t r,const size_t c): _rows(r),_cols(c),_data(new T[r*c]{})
        {

        }
        // 解决深拷贝问题！  这个没有返回值！  拷贝 构造 ！
        Mat(const Mat& other)
        {
            this->_rows=other._rows;
            this->_cols=other._cols;

            this->_data = new T[_rows*_cols]();
        }
        T getElement (size_t r, size_t c)
        {   
            if(r>=this->_rows || c>=this->_cols)
            {
                std::cerr<<"Indices are out of range"<<std::endl;
                //return 0;
            }
            return  _data[r*this->_cols+c];
        }

        void setElement(size_t r, size_t c, T value)
        {

            if(r>=this->_rows || c>=this->_cols)
            {
                std::cerr<<"Indices are out of range"<<std::endl;
               
            }

            _data[r*this->_cols+c]= value;
        }

        ~Mat()
        {
            delete [] _data; // 数组 指针 ！ 当做 数组 名
        }  

};


int main()
{

    Mat<double> m;
    Mat<int> m2(3,4);
    Mat<int> m3(m2);
    m2.setElement(1,2,256);
    std::cout<<m2.getElement(1,2)<<std::endl;


    return 0;
}




