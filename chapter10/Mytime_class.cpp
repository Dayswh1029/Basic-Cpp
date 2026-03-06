#include<iostream>

class Mytime{
    private:
        int hours;
        int minutes;
    public:
        Mytime(){
            hours=0;
            minutes=0;
        };
        Mytime(int h,int min):hours(h),minutes(min)
        {
            std::cout<<"constructor: Mytime(int, int);"<<std::endl;
        }
        // 转换为 string 类型！
        std::string getTime()const
        {
            return std::to_string(this->hours)+" hours and "
                +std::to_string(this->minutes)+" minutes.";
        }
        // converting constructor  即输入一个整数 例如200  参数构造！ int 转换为  hours  and  minutes 
        Mytime(int m):hours(0),minutes(m)
        {
            std::cout<<"Constructor Mytime(int m)"<<std::endl;
            this->hours=this->minutes/60;
            this->minutes%=60;
        }



        ~Mytime(){}
        //下面是overloading operator
        //1, operator + 重载的+ 一定要注意60 进一！！
        Mytime operator+(const Mytime& other)const
        {
            Mytime temp;
            temp.hours=this->hours+other.hours;
            temp.minutes=this->minutes+other.minutes;
            if(temp.minutes>=60)
            {
                temp.hours=temp.hours+(temp.minutes/60);
                temp.minutes=(temp.minutes%60);
            }
            return temp;
        }
        //2, operator+=
        Mytime& operator+=(const Mytime& other)
        {
            this->hours+=other.hours;
            this->minutes+=other.minutes;
            this->hours+=this->minutes/60;
            this->minutes%=60;

            return *this;
        }
        //3. Mytime + scalar 
        Mytime operator+(int scalar)const
        {
            Mytime temp;
            temp.minutes=this->minutes+scalar;
            temp.hours=this->hours+temp.minutes/60;
            temp.minutes=temp.minutes%60;
            return temp;
        }

        //4, assignment operator overloading =
        Mytime& operator=(const Mytime & other)
        {
            this->hours=other.hours;
            this->minutes=other.minutes;
            return *this;
        }
        Mytime& operator=(int m)
        {
            this->hours=0;
            this->minutes=m;
            this->hours=this->minutes/60;
            this->minutes %=60;
            return *this;
        }
        //5, operator++  prefix increment  ++m!
        Mytime& operator++()
        {
            this->minutes++;
            this->hours+=this->minutes/60;
            this->minutes=this->minutes%60;
            return *this;
        }
        //6, postfix increment    m++ 

        Mytime operator++(int)
        {
            Mytime temp=*this;
            ++(*this);
            return temp;
        }
        


        //6, operator++  postfix increment

        /* 
            类型转换！！user-defined Type Conversion
            operator type()
            overloading  operator type()

        */
        // implicit conversion 
        operator int()const
        {
            return this->hours*60+this->minutes;
        }
        // explicit conversion 
        explicit operator float()const{
            return float(this->hours*60+this->minutes);
        }
        

        //下面是友元函数！

        //4, scalar + Mytime  
        friend Mytime operator+(int scalar, const Mytime& other)
        {
            return other+scalar;
        }

        friend std::istream & operator>>(std::istream & is,  Mytime& other)
        {
            is>>other.hours>>other.minutes;
            other.hours +=other.minutes /60;
            other.minutes %=60;
            return is;

        }

        friend std::ostream& operator<<(std::ostream& os, const Mytime& other)
        {
            os<<other.hours<<" hours "<<other.minutes<<" minutes";

            return os;
        }
};

int main ()
{
    Mytime t1(2,40);
    Mytime t2(1,40);
    std::cout<<(t1+t2).getTime()<<std::endl;
    std::cout<<t1+t2<<std::endl;
    Mytime t1, t2;
    std::cin >> t1 >> t2;      // 输入运算符

    std::cout<<t1.getTime()<<std::endl;
    std::cout<<t2.getTime()<<std::endl;
    Mytime t3(10,40);
    t3+=t2;
    t3.operator+=(t2); //function 
    std::cout<<t3.getTime()<<std::endl;

    Mytime t5(130);
    std::cout<<t5.getTime()<<std::endl;


    return 0;
}