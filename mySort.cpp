#include <iostream>
using namespace std;

const int N=9;

int main(){
    int arr_B[N]={98,45,32,101,54,77,68,89,99};
    int arr_S[N]={98,45,32,101,54,77,68,89,99};
    //Bubble Sort
    for (int j = N-1; j>=0; j--)    //循环确定当前最值并排序到最后
    {
        for(int i=0;i<j;++i){
            if(arr_B[i]<arr_B[i+1]){    //可通过'<','>'调整顺序,相当于运算符重载
                int tmp=arr_B[i];
                arr_B[i]=arr_B[i+1];
                arr_B[i+1]=tmp;
            }
        }
    }
    
    for(int i=0;i<N;++i){cout<<arr_B[i]<<" ";}
    
    cout<<endl<<endl;

    //Selection Sort
    for(int i=0;i<N;i++){
        int posMax=i;
        //找到posMax
        for(int pos=i;pos<N;++pos){
            if(arr_S[posMax]<arr_S[pos]){posMax=pos;}   //可通过'<','>'调整顺序,相当于运算符重载,posMax或posMin
        }
        int tmp=arr_S[i];
        arr_S[i]=arr_S[posMax];
        arr_S[posMax]=tmp;
    }
    for(int i=0;i<N;++i){cout<<arr_S[i]<<" ";}

    return 0;
}