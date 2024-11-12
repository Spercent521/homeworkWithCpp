#include <iostream>
#include <random>
using namespace std;

// Bin 二进制
// Oct 八进制
// Dec 十进制
// Hex 十六进制

int main(){
    // 创建随机数引擎，使用随机设备作为种子
    std::random_device rd;
    std::mt19937 gen(rd());

    // 定义一个1到1000之间的均匀分布
    std::uniform_int_distribution<> dis(1, 1000);

    // 生成一个随机数
    int random_number = dis(gen);
    
    cout<<"your number is :"<<random_number<<endl;

    string s;

    while(random_number){
        if(random_number%2){s='1'+s;}else{s='0'+s;}
        random_number=random_number>>1;
    }

    cout<<s<<endl;

    return 0;
}