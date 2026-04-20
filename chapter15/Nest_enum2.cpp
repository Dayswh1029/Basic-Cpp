#include<iostream>
class Mat
{
    public:
        enum Datatype
    {
        TYPE8U,
        TYPE8S,
        TYPE32F,
        TYPE64F

    };
    private:
        Datatype type;
        void *data;
    public:
        Mat(Datatype type): type(type),data(nullptr){}
        Datatype getType() const {return type;}
};

int main()
{
    Mat imag(Mat::Datatype::TYPE8U);
    if(imag.getType()==Mat::Datatype::TYPE8U)
    {
        std::cout<<"This is an 8U matrix."<<std::endl;

    }
    else
        std::cout<<"i am not an 8U matrix."<<std::endl;

    return 0;
}