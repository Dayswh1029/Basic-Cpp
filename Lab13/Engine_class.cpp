#include<iostream>

//  class  include a classs
class Engien
{
    private:
        int cylinder;
       
    public:
        Engien(int nc):cylinder(nc)
        {
            std::cout<<"Constructor: Engine(int)"<<"\n";
        }
        int getCylinder()
        {
            return this->cylinder;
        }
        ~Engien(){}
        void start()
        {
            std::cout<<getCylinder()<<"cylinder engine started"<<std::endl;
        }
};

class car
{

    private:
        Engien eng;
        std::string Brand;
    public:
        car():eng(4),Brand("Default"){}
        car(int n, const  std::string& B):eng(n),Brand(B)
        {
            std::cout<<"Constructor: car(int, cosnt std::string )"<<std::endl;
        }
        void start()
        {
            std::cout<<"car with "<<eng.getCylinder()<<"cylinder engine started"<<std::endl;
            eng.start();
        }
        ~car()
        {
            std::cout<<"Destructor: ~car()\n";
        }

};


int main()
{
    car car1;
    car car2(8,"huawei");
    car1.start();
    car2.start();

    return 0;
}