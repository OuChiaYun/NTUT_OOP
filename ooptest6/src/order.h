#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <vector>
#include <string.h>
#include "alcohol.h"


using namespace std;

class Order
{
    public:
// private:
    vector<Alcohol*> _alcohol_list = {};
    int _t_price = 0;
// public:
    Order()= default;
    ~Order() = default;
    void append_alcohol(Alcohol* alcohol){


        _alcohol_list.push_back(alcohol);
        _t_price = _t_price + alcohol->get_price();
        
    }
    int get_alcohol_count(){
        return _alcohol_list.size();
    }
    int get_total_price(){
        return _t_price;
    }
};

#endif
