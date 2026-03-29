#include<iostream>

// class Template 

template<typename T>
class Myvector
{
    private:

        size_t len;
        T* _data;
    public:
        Myvector(size_t len):len(len)
        {
            _data= new T[len]{};
        }
        Myvector(const Myvector&)=delete;
        Myvector& operator=(const Myvector&)=delete;
        T getElement(size_t index);
        bool setElement(size_t index, T value);
        ~Myvector()
        {
            delete[] _data;
            _data=nullptr;
        }

};
template<typename T>
T Myvector<T>::getElement(size_t index)
{
    if(index>=this->len)
    {
       // 需要 throw  ! 抛出错误！ 否则 会返回 return _data[index];
        throw std::out_of_range("getElement(): index out of range");
    }
    return _data[index];

}
template<typename T>
bool Myvector<T>::setElement(size_t index, T value)
{
    if(index>=this->len)
    {
        std::cerr<<"setElement(): Indices are out of range"<<std::endl;
        return false;
    }
    _data[index]=value;
    return true;
}


//template class Myvector<int>; //显式实例化 

// class  specialization   类的特例化！！！
template<typename T> class Vector;  // 必须 事前声明 一下！！！
template<> class Vector<bool>
{
    private:
        size_t length;
        unsigned char* _data;
    public:
        Vector(size_t length):length(length)
        {
            int num_bytes=(length-1)/8+1;
            _data=new unsigned char[num_bytes]{};

        }
        ~Vector()
        {
            delete [] _data;
            _data=nullptr;

        }
        Vector(const Vector&)=delete;
        Vector& operator=(const Vector&)=delete;

        bool getElement(size_t index);
        bool setElement(size_t index, bool value);

};
bool Vector<bool>::getElement(size_t index)
{
    if(index>=this->length)
    {
       // 需要 throw  ! 抛出错误！ 否则 会返回 return _data[index];
        throw std::out_of_range("getElement(): index out of range");
    }
    size_t byte_id = index/8;
    size_t bit_id = index%8;
    unsigned char mask=(1<<bit_id);


    return bool(_data[byte_id] & mask);

}
bool Vector<bool>::setElement(size_t index, bool value)
{
    if(index>=this->length)
    {
       // 需要 throw  ! 抛出错误！ 否则 会返回 return _data[index];
        throw std::out_of_range("setElement(): index out of range");
    }
    size_t byte_id = index/8;
    size_t bit_id = index%8;
    unsigned char mask=(1<<bit_id);

    if(value)
    {
        _data[byte_id]|=mask;
    }
    else
    {
        _data[byte_id] &=~mask;
    }
    return true ;

}


int main()
{
    Myvector<int> vec(16);
    vec.setElement(3,100);
    std::cout<<vec.getElement(3)<<std::endl;

    Vector<bool> boolvector(17);
    boolvector.setElement(15,false);
    boolvector.setElement(16,true);
    std::cout<<boolvector.getElement(15)<<std::endl;
    std::cout<<boolvector.getElement(16)<<std::endl;

    return 0;
}