#include <iostream>
using namespace std;

int swap_add(int a,int b);

int main(){
    int a,b;
    cin>>a>>b;

    int ans=swap_add(a,b);
    cout<<ans<<endl<<endl;
    return 0;
}

int swap_add(int a,int b){
    return a%10*1000+a/10*10+b/10+b%10*100;
}