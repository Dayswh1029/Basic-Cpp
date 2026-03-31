#include<iostream>

// 写一个  Pair 
template<typename T , typename U>
class Pairs
{
    private:
        T key;
        U value;
    public:
        Pairs():key(),value()
        {   }
        Pairs(T k,U v):key(k),value(v)
        {} 
        Pairs(const Pairs& other)
        {
            
            this->key=other.key;
            this->value=other.value;
        }
        Pairs& operator=(const Pairs& other)
        {
            if(&other!=this)
            {
                this->key=other.key;
                this->value=other.value;
                return *this;
            }
            return *this;
        }

        bool operator<(const Pairs& other) const
        {
            if(this->key<other.key)
            {
                return true;
            }
            return false;
        }
        friend std::ostream& operator<<(std::ostream& os, const Pairs& other)
        {

            os<<"Pairs key :"<<other.key<<",  value: "<<other.value<<"; \n";
            return os;
        }

};


int main()
{
    Pairs<int, int> P1(1,3),P2(4,5);
    std::cout<<P1<<"\n";
    std::cout<<(P1<P2)<<std::endl;
    Pairs<std::string,int>P3("A",23);
    Pairs<std::string,int>P4("B",300);
    std::cout<<(P4<P3)<<std::endl;

    return 0;
}