#include<iostream>
#include <algorithm>
using namespace std;

bool complare(int a,int b){
	return a>b;
} 

int main(){
 	int a[10]={2,4,1,23,5,76,0,43,24,65};
 	
	//列印原陣列 
	for(int i=0;i<10;i++){
 		cout<<a[i]<<" ";
 	}
 	cout<<endl;
	
	//排序  	
	sort(a,a+10,complare);
 	
	//列印排序後的陣列 
	for(int i=0;i<10;i++){
 		cout<<a[i]<<" ";
 	}
    cout <<endl;
	return 0;
}