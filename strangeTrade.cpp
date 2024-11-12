#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    cout<<n*100000<<endl;
    
    if(n==0){cout<<0;return 0;}
    if(n==1){cout<<0;return 0;}
    long long int sum=1;
    long long int daySalray=1;
    for(int i=2;i<=n;++i){
        daySalray=daySalray*2;
        sum+=daySalray;
    }
    cout<<sum;

    return 0;
}