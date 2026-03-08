#include<iostream> 
#include<string>
#include<memory>

// 智能指针！！！！unique_ptr
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

    std::unique_ptr<Mytime> mt1(new Mytime(10));
    std::unique_ptr<Mytime> mt2=std::make_unique<Mytime>(80);
    std::cout<<"mt1: "<<*mt1<<std::endl;
    std::cout<<"mt2: "<<*mt2<<std::endl;


    // 不能拷贝！！！
    std::unique_ptr<Mytime> mt3=std::move(mt1); // 必须使用 move()!
    std::cout<<"mt3: "<<*mt3<<std::endl;



    return 0;
}