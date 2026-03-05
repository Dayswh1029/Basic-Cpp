#include<iostream>
// 创建一个 Box。
class Box{
    private:
        double length; 
        double breadth;
        double height;
    public:
        // default constructor 
        Box();
        //parameterized constructor
        Box(double length,double breadth,double height);
        ~Box()
        {
            std::cout<<"destructor: ~Box()"<<std::endl;
        }
        void setLength(double length);
        double getLength();
        void setBreadth(double breadth);
        double getBreadth();
        void setHeight(double height);
        double getHeight();
        void printInfo();
};
 //无参构造的实现！
Box::Box()
{
    length =0.0;
    breadth=0.0;
    height=0.0;
}
Box::Box(double length,double breadth, double height)
    :length(length),breadth(breadth),height(height)
    {
        std::cout<<"constructor: Box(parameters )"<<std::endl;
    }
void Box::setLength(double length)
{
    this->length=length;

}
double Box::getLength(){
    return this->length;
}

void Box::setBreadth(double breadth)
{
    this->breadth=breadth;

}
double Box::getBreadth(){
    return this->breadth;
}
void Box::setHeight(double height)
{
    this->height=height;

}
double Box::getHeight(){
    return this->height;
}
void Box::printInfo()
{
    std::cout<<"The length:  "<<this->length<<std::endl;
    std::cout<<"The breadth: "<<this->breadth<<std::endl;
    std::cout<<"The height:  "<<this->height<<std::endl;

}

int main()
{
    Box b1;
    b1.printInfo();
    b1.setLength(3.0);
    b1.setBreadth(4.0);
    b1.setHeight(5.0);
    b1.printInfo();

    Box b2(6.0,7.0,9.0);
    b2.printInfo();

    return 0;
}