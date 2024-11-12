#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int salaryLevel;
    double s,ans;
    cin>>s;
    salaryLevel=s/1000;

    switch(salaryLevel){
        case 0:
            cout << fixed << setprecision(2) << s ;
        break;
        case 1:
            cout << fixed << setprecision(2) << s*0.9 ;
        break;
        case 2:
            cout << fixed << setprecision(2) << s*0.85 ;
        break;
        case 3:
            cout << fixed << setprecision(2) << s*0.80 ;
        break;
        default:
            cout << fixed << setprecision(2) << s*0.75 ;
        break;
    }
    
    return 0;
}