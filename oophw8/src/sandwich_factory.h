#ifndef SWEET_SANDWICH_FACTORY_H
#define SWEET_SANDWICH_FACTORY_H

#include <iostream>
#include <vector>
#include "sandwich.h"
#include "../src/beef_sandwich.h"
#include "../src/sweet_sandwich.h"

using namespace std;

template <class T>

class SandwichFactory
{

public:
    static T *create_sandwich(int price, int id)
    {
        T *s = new T(price, id);
        return s;
    };

    static vector<T *> create_sandwich_array(int price, int count, std::vector<int> id_list){
        if(count < 0){
            throw std::invalid_argument("wrong");
        }
        vector<T*> s = {};
        for(int i = 0;i<count;i++){
            s.push_back(SandwichFactory<T>::create_sandwich(price,id_list[i]));
        }
        return s;
    };
};

#endif