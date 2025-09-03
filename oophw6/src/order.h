#ifndef ORDER_H
#define ORDER_H

#include<iostream>
#include<vector>
#include"alcohol.h"



using namespace std;

class Order {

    public:
    // protected : 
        vector <Alcohol*> _alcohol_list;
        int _total_price = 0;

    // public:

        Order()= default;
        ~Order() = default;

        void append_alcohol(Alcohol* alcohol){
            _total_price += alcohol->get_price();
            _alcohol_list.push_back(alcohol);

        };
        int get_alcohol_count(){
            return _alcohol_list.size();
        };
        int get_total_price(){
            return _total_price;
        };

};




#endif