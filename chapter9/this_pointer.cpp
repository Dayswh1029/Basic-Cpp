#include<iostream>
#include<cstring>
class Student{
    private:
        char* name;
        int born;
        bool male;
    public:
        Student()
        {
           this-> name =new char[1024]{0};
           this-> born=0;
           this-> male=false;
            std::cout<<"Constructor: Student()"<<std::endl;
        }
        Student(const char* initName,int initBorn,bool isMale)
        {
            this->name=new char[1024]; 
            this->setName(initName);
            this->born=initBorn;
            this-> male=isMale;
            std::cout<<"Constructor: Student(const char*)"<<std::endl;

        }
        ~Student()
        {
            std::cout<<"To destroy object: "<<name<<std::endl;
            delete [] name;
            this->name=nullptr;
        }

        void setName(const char* name) // 参数！
        {
            strncpy(this->name,name,1024); 
            // this——>name 中的name是对象属性； 后面的name是变量参数
        }
        void setBorn(int born)
        {
            this->born=born;
        }
        // the declaration, the definitions are out of the class!
        void setGender(bool isMale);
        void printInfo();

};
void Student::setGender(bool isMale)
{
    this->male=isMale;
}
void Student::printInfo()
{
    std::cout<<"Name: "<<name<<std::endl;
    std::cout<<"Born on: "<<born<<std::endl;
    std::cout<<"Gender: "<<(male ? "Male": "Female")<<std::endl;
}
int main()
{

    // 创建array 指针 可以数组的操作！
    Student * class1= new Student[3]{

        {"Tom",2000,true},
        {"Bob",2002,false},
        {"Amy",2000,true},
    };
    class1[1].printInfo();
    class1->printInfo(); // class1为 指针！ class1[0] 
    class1[2].printInfo();




}
