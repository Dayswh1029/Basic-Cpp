#pragma once
#include<iostream>

class Rational{
    private:
        static int id; // 用来计数！ 而且必须在类外初始化！！
        int numerator;
        int denominator;
    public:
        // 增加了 explicit 就意味着舍去了Implicit 隐式！
        //Rational(int n=0, int d=1):numerator(n),denominator(d)
        // 上下的区别！！！
        explicit Rational(int n=0, int d=1):numerator(n),denominator(d)
        {
            std::cout<<"Constructor_ "<<++id<<", n:"<<numerator
            <<",d: "<<denominator<<std::endl;
        }
        ~Rational(){}
        int getN() const {return numerator;}
        int getD() const {return denominator;}
        // 处理 Rational * int
        friend Rational operator*(const Rational& lhs, int rhs) {
            return Rational(lhs.getN() * rhs, lhs.getD());
        }
        // 处理 int * Rational (利用上面的函数，避免重复逻辑)
        friend Rational operator*(int lhs, const Rational& rhs) {
            return rhs * lhs; 
        }

        friend std::ostream& operator<<(std::ostream& os,const Rational& rhs)
        {
            os<<rhs.numerator<<"/"<<rhs.denominator;
            return os;
        }
};
int Rational::id=0;

const Rational operator*(const Rational&lhs, const Rational& rhs)
{
    return Rational(lhs.getN()*rhs.getN(),lhs.getD()*rhs.getD());

}






