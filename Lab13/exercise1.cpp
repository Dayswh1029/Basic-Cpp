#include<iostream>
#include<cmath>

// Point class 
class Point{

    private:
        double x,y;
    public:
        Point(){}
        Point(double x, double y):x(x),y(y)
        {    }
        // 2. 正确的拷贝构造函数
        Point(const Point& other) {
            this->x = other.x;
            this->y = other.y;
        }

    // 3. 正确的赋值运算符
    Point& operator=(const Point& other) {
        if (this != &other) { // 防止自赋值
            this->x = other.x;
            this->y = other.y;
        }
        return *this;
        }
        double getX()
        {
            return this->x;
        }
        double getY()
        {
            return this->y;
        }

};
class Distance{
    private:
        Point p1,p2;
        double D;
    public:
        Distance():p1(0,0),p2(0,0)
        {}
        Distance(Point p1, Point p2):p1(p1),p2(p2)
        { }

        double CalDis(Point p1,Point p2)
        {
            return sqrt((p1.getX()-p2.getX())*(p1.getX()-p2.getX())+
            (p1.getY()-p2.getY())*(p1.getY()-p2.getY()));
        }

};


int main()
{
    Point p;
    Point p2(1,1);
    Point p3(3,4);
    Distance d;
    Distance d2(p2,p3);
    double result =d2.CalDis(p2,p3);
    std::cout<<result<<std::endl;

    return 0;
}