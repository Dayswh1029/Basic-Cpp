#include<iostream> 
#include<string>
#include<memory>

// 智能指针！！！！
class Mytime{

    private:
        int hours;
        int minutes;

    public:
        Mytime():hours(0),minutes(0){
            std::cout<<"Constructor Mytime()"<<std::endl;
        }
        Mytime(int m):hours(0),minutes(m)
        {
            std::cout<<"Constructor Mytime(int )"<<std::endl;
            this->hours+=this->minutes/60; // 这个+ 是否可以省去？？？
            this->minutes=this->minutes%60;
        }
        Mytime(int h,int min):hours(h),minutes(min){
            std::cout<<"Constructor Mytime(int,int)"<<std::endl;
            this->hours+=this->minutes/60;
            this->minutes%=60;
        }
        ~Mytime()
        {
            std::cout<<"Destructor Mytime(), Bye"<<std::endl;
        }
        Mytime operator+(int m) const
        {
            Mytime sum;
            sum.minutes=this->minutes+m;
            sum.hours=this->hours;
            sum.hours+=sum.minutes/60;
            sum.minutes%=60;
            return sum;
        }
        friend  std::ostream& operator<<(std::ostream& os, const Mytime& other)
        {
            std::string str=std::to_string(other.hours)+" hours and "
                            + std::to_string(other.minutes)+ " minutes.";
            os<<str;

            return os;
        }

};



int main()
{
    std::shared_ptr<Mytime> mt1= std::make_shared<Mytime>(100); // 参数 一个！
    std::shared_ptr<Mytime> mt2=mt1;
    std::shared_ptr<Mytime> mt3=mt2;
    std::cout<<mt1.use_count()<<std::endl;
    // 类对象实例！ 因为shared_ptr 重载了* 
    std::cout<<*mt1<<std::endl;
    std::cout<<*mt2<<std::endl;
    std::cout<<*mt3<<std::endl;
    //地址 
    std::cout<<mt1<<std::endl;
    std::cout<<mt2<<std::endl;
    std::cout<<mt3<<std::endl;
    std::cout<<mt2.use_count()<<std::endl;

    {
        auto mt4=mt3;
        *mt4=*mt4+50; // 重载了 Mytime + int
        std::cout<<"use_count() = "<<mt3.use_count()<<std::endl;
    } 
    // 括号结束，变量消失！！！
    std::cout<<*mt3<<std::endl; // 改变了对象的值！！！
    std::cout<<"use_count() = "<<mt3.use_count()<<std::endl;




    auto mt8=std::make_shared<Mytime>(2,100); // 两个参数！






    return 0;
}