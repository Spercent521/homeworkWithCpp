#include <iostream>
#include <cmath>
using namespace std;

int a[5]={19,24,40,37,11}, b[5]={3,17,9,7,20}, c[10]={0}; 

void mySort(int arr[],int num){
    int maxPos=0;
    int ans[10]={0};
    for(int i=0;i<num;++i){
        //find max
        for(int j=0;j<num;++j){
            if(arr[maxPos]<=arr[j]){
                maxPos=j;
            }
        }
        ans[i]=arr[maxPos];
        arr[maxPos]=-1;
    }
    for(int i=0;i<num;++i){
        arr[i]=ans[i];
    }
}

bool isprime(int n){
    for(int i=2;i<=sqrt(n);++i){
        if(n%i==0){return false;}
    }
    return true;
}

int main(){
    // int startNum=0,Num=0;
    // cin>>startNum>>Num;
    // for(;Num>0;){
    //     if(isprime(startNum)){
    //         --Num;
    //         cout<<startNum<<" ";
    //     }
    //     ++startNum;
    // }
    int num=0;
    for(int i=0;i<5;++i){
        if(isprime(a[i])){c[num]=a[i];++num;}
    }
    for(int i=0;i<5;++i){
        if(isprime(b[i])){c[num]=b[i];++num;}
    }

    mySort(c,num);

    cout<<num<<endl<<endl;
    for(int i=0;i<num;++i){
        cout<<c[i]<<" ";
    }

    return 0;
}