#include <iostream>
using namespace std;

bool isAnum(int n);

int main(){
    int a,b,cnt=0;
    cin>>a>>b;
    if(a>b||a<0){cout<<"error";return 0;}
    for(int i=a;i<=b;++i){
        if(cnt==0&&isAnum(i)){
            cout<<i;
            ++cnt;
            continue;
        }
        if(cnt!=0&&isAnum(i)){
            cout<<endl<<i;
        }
    }
    if(cnt==0){cout<<"no";}

    return 0;
}

bool isAnum(int n){
    int tmp=n,l=0;
    while(tmp!=0){
        ++l;
        tmp=tmp/10;
    }
    tmp=n;
    int sum=0;
    while(tmp!=0){
        int dx=1;
        for (int i = 0; i <l; i++)
        {
            dx=dx*(tmp%10);
        }
        sum+=dx;
        tmp=tmp/10;
    }
    if(sum==n){return true;}else{return false;}
}