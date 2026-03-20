#include<iostream>
#include<string>
class Employee{

    private:
        std::string name;
        std::string ssn;
    public:
        Employee(const std::string& n, const std::string & s):name(n),ssn(s)
        {
            std::cout<<"The base class constructor is invoked:"<<std::endl;
        }
       virtual ~Employee()
        {
            std::cout<<"The base class destructor is invoked. "<<std::endl;
        }
        std::string getName() const
        {
            return name;
        }
        std::string getSSN() const
        {
            return ssn;
        }
        void setName(const std::string& n)
        {
            this->name=n;
        }
        void setSSN(const std::string & s)
        {
            this->ssn=s;
        }
        double earning()
        {
            return 0;
        }
        // 虚函数！
        virtual void show()
        {
            std::cout<<"Name is: "<<this->name<<", SSN number is: "<<ssn<<std::endl;
        }

};
class SalariesEmployee:public Employee{
        private:
            double salary;
        public:
        SalariesEmployee(const std::string& name, const std::string& ssn, double s):
            Employee(name,ssn),salary(s)
            {
                std::cout<<"The derived class constructor is involked. "<<std::endl;
            }
        ~SalariesEmployee()
        {
            std::cout<<"The derived class destructor is involked. "<<std::endl;

        }
        SalariesEmployee(const Employee& e, double s)
        :Employee(e), salary(s){ }

        double getSalary()const { return salary; }
        void setSalary(double s) { salary=s; }
        double earning(){ return getSalary();}
        void show()
        {
            std::cout<<"Name is:"<<getName()<< ", SSN number is: "
            <<getSSN()<< ", salary is:"<<salary<<std::endl;
        }                

};




int main()
{
    Employee e("wangh","2000");
    SalariesEmployee se("WangFang","1001",2000);

    // 
    Employee * pe= &e;
    pe->show();
    // 多态！
    pe=&se;
    pe->show();
    e.Employee::show();

    delete[] pe;


    return 0;
}
