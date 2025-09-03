#ifndef COOKIE_H
#define COOKIE_H

#include<iostream>
#include<cmath>
using namespace std;


double max_dv(int n,int *array){



    if(n<0){
        return -1;
    }

    for(int i = 0; i < n; i++){
		int dv = array[i];
		if(dv < 0 || dv > 100){
			return -1;
		}
	}

        int to = 0;
        int te = 0;


    for (int i = 0;i<n ;i++){

        if(i%2 == 0){
            // Total the dv on every odd position.
            to += array[i];

        }else{
            // Total the dv on every even position.
            te += array[i];
        }
    }

    return (to < te ?te :to);
};

#endif // end of include guard: COOKIE_H
