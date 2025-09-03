#include<iostream>

using namespace std;

int func(int n,int a[]){


    int t_o = 0;
    int t_e = 0;

    if(n <0){
        return -1;
    }

    for (int i = 0;i<n;i++){
        if (a[i] <0){
            return -1;
        }
        if((i+1)%2 == 0){
            t_e+= a[i];
        }else{
            t_o+= a[i];
        }

    }

    if (t_o >= t_e){
        return t_o;
    }else{
        return t_e;
    }

}
