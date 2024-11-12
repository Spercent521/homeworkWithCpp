#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    int m,n;
    cin>>n>>m;
    double s=0,h=0;
    //s
    if (m==1){
        s=n;
        //h
        h=n*pow(0.25,m);
    }else{
        --m;
        s=n*(1+2*(1-pow(0.25,m))/3);
        //h
        h=n*pow(0.25,m+1);
    }

    cout << fixed << setprecision(2) << s ;
    cout<<endl;
    cout << fixed << setprecision(2) << h ;

    return 0;
}