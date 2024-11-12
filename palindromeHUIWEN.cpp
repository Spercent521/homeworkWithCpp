//判断字符串是否为回文
#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    getline(cin,s);     //要读取一整行 getline 在<string>中
    int leftPos=0;
    int rightPos=s.size()/sizeof(char)-1;
    //从两端开始比较
    while(leftPos!=rightPos){
        while(s[leftPos]<65||s[leftPos]>122||(s[leftPos]>90&&s[leftPos]<97)){++leftPos;}
        while(s[rightPos]<65||s[rightPos]>122||(s[rightPos]>90&&s[rightPos]<97)){--rightPos;}
        if(s[leftPos]!=s[rightPos]&&
            ((s[leftPos]-s[rightPos])!='a'-'A')&&
            ((s[rightPos]-s[leftPos])!='a'-'A')){
            cout<<"NO"<<endl;
            return 0;
        }
        ++leftPos;--rightPos;
    }

    cout<<"YES"<<endl;

    return 0;
}