#include<iostream>
#include <cstdint> // 包含 uint32_t 和 uint8_t 的定义

union ipv4address{
    std::uint32_t address32; //
    std::uint8_t address[4]; // 
};

int main()

{
    union ipv4address ip;
    std::cout<<"sizeof(ip) = "<<sizeof(ip)<<std::endl; // 4
    ip.address[0]=1;
    ip.address[1]=0;
    ip.address[2]=0;
    ip.address[3]=127;
    std::cout << "IP components: "   // (int)ip.address[]
              << +ip.address[3] << "." 
              << +ip.address[2] << "." 
              << +ip.address[1] << "." 
              << +ip.address[0] << std::endl;
    std::cout<<std::hex;
    std::cout<<"in hex "<<ip.address32<<std::endl;

    return 0;
}