#include<iostream>


enum Datatype
{
    TYPE8U,
    TYPE8S,
    TYPE32F,
    TYPE64F

};
class Mat
{
    private:
        Datatype type;
        void *data;
    public:
        Mat(Datatype type): type(type),data(nullptr){}
        Datatype getType() const {return type;}
};


int main()
{
    Mat imag(TYPE8U);
    if(imag.getType()==TYPE8U)
    {
        std::cout<<"This is an 8U matrix."<<std::endl;

    }
    else
        std::cout<<"i am not an 8U matrix."<<std::endl;

    return 0;
}