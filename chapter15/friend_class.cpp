#include<iostream>
class Sniper
{
    private:
        int bullets;
    public:
        Sniper(int bullets=0):bullets(bullets)  { }
        friend class Supplier; // 友元类！  友元类可以访问任意的 类！ 
};
class Supplier
{
    private:
        int storage;
    public:
        Supplier(int storage=1000):storage(storage){}
        bool provide(Sniper& sniper)
        {
            // bullets is a private member
            if(sniper.bullets<20)
            {
                if(this->storage>100)
                {
                    sniper.bullets +=100;
                    this->storage-=100;
                }
                else if(this->storage>0)
                {
                    sniper.bullets +=this->storage;
                    this->storage=0;
                }
                else
                    return false;
            }
            std::cout<<"Sniper has "<<sniper.bullets<<" bullets now."<<std::endl;
            return true;
        }
};

int main()
{
    Sniper sniper(2);
    Supplier supplier(2000);
    supplier.provide(sniper);


    return 0;
}