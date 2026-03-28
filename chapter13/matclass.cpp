#include<iostream>

class Mat{
    private:
        size_t _rows;
        size_t _cols;
        double* _data;
    public:
        Mat():_rows(0),_cols(0),_data(nullptr)
        {

        }
        Mat(const size_t r,const size_t c): _rows(r),_cols(c),_data(new double[r*c])
        {

        }
        // 解决深拷贝问题！  这个没有返回值！  拷贝 构造 ！
        Mat(const Mat& other)
        {
            this->_rows=other._rows;
            this->_cols=other._cols;

            this->_data = new double[_rows*_cols]();
        }
        double getElement (size_t r, size_t c)
        {   
            if(r>=this->_rows || c>=this->_cols)
            {
                std::cerr<<"Indices are out of range"<<std::endl;
                return 0;
            }
            return  _data[r*this->_cols+c];
        }

        void setElement(size_t r, size_t c, double value)
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

    Mat m;
    Mat m2(3,4);
    Mat m3(m2);
    m2.setElement(1,2,256);
    std::cout<<m2.getElement(1,2)<<std::endl;


    return 0;
}