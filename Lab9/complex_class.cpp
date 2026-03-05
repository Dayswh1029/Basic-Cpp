#include<iostream>
// complex class

class Complex
{
    private:
        double real;
        double imag;
    public:
        Complex():real(0),imag(0) // 采用默认值 
        {
            std::cout<<"constructor: Complex()"<<std::endl;
        }
        Complex(double real,double imag):real(real),imag(imag) // list 
        {
            std::cout<<"constructor: Complex(double,double)"<<std::endl;
        }
        ~Complex()
        {
            std::cout<<"destructor: ~Complex();"<<std::endl;
        }
        //1, c3=c1+c2  operator+  
        Complex operator+(const Complex& c)const
        {
            Complex temp;
            temp.real=this->real+c.real;
            temp.imag=this->imag+c.imag;
            return temp;  // 返回值 不可以是引用！ 
        
        }
        //2. operator=
        Complex& operator=(const Complex& other)
        {
            this->real=other.real;
            this->imag=other.imag;
            return *this;
        }

        //3. operator *
        Complex operator*(const Complex& other)const
        {
            return Complex(this->real*other.real+(-1)*this->imag*other.imag,
            (this->real*other.imag+this->imag*other.real));
        }
        //4, Complex *scalar
        Complex operator*(double scalar) const
        {
            return Complex(this->real*scalar,this->imag*scalar);
        }
        //5, Scalar *Complex
      
        friend  Complex operator*(double scalar,const Complex& other)
        {
            return other*scalar;
        }
        //5, operator += 
        Complex& operator+=(const Complex& other)
        {
            this->real=(this->real+other.real);
            this->imag=(this->imag+other.imag);
            return *this;

        }
        //6, 一目运算符 operator-  不要碰 this ！返回一个 临时的complex
        Complex operator-()const
        {
            return Complex(-real,-imag);
        }

        //6, ostream& << 的overloading
        // 重载实现 一定注意！ 这个不是成员函数！是友元！ 
       friend std::ostream& operator<<(std::ostream& os, const Complex& other) {
            os << "Complex(" << other.real <<","<< other.imag << ")";
            std::cout<<"\n";
            return os; // 返回流本身，这是实现 cout << p1 << p2 << endl 的关键
        }
};

int main()
{
    Complex c1;
    Complex c2(1.0,3.0);
    Complex c3;
    c3=c1+c2;
    std::cout<<c3;
    std::cout<<(c3*c2)<<std::endl;
    return 0;
}


//以后再慢慢的补充复数计算的重载！