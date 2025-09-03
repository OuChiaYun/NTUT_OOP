#ifndef CAKESHOWCASE_H
#define CAKESHOWCASE_H

#include <iostream>
#include "chocolate_cake.h"
#include "geode_cake.h"
#include "honey_cake.h"
#include "cake.h"

using namespace std;

template <typename T>

class CakeShowcase
{

private:
    T *_arr[256];
    int _length;

public:
    ~CakeShowcase(){
        // delete[] *_arr;
    }
    CakeShowcase(int length, T **array)
    {
        _length = length;
        for (int i = 0; i < _length; i++)
        {
            _arr[i] = array[i];
        }
    };
    int calc_total_price()
    {
        int count = 0;
        for (int i = 0; i < _length; i++)
        {
            count += _arr[i]->get_price();
        }
        return count;
    };
    int calc_total_sweet()
    {
        int count = 0;
        for (int i = 0; i < _length; i++)
        {
            count += _arr[i]->get_sweet();
        }
        return count;
    };
    std::string to_string()
    {
        // char sum[256] = {'0'};
        // string str;
        // char* sum;
        string sum = "| CakeName             | Price      | Sweet      |\n| -------------------- | ---------- | ---------- |\n";

        for (int i = 0; i < _length; i++)
        {
            sum.append(_arr[i]->to_string() );
            sum.append("\n");
        }
        sum.append("| -------------------- | ---------- | ---------- |");
        // cout <<sum << endl;
        return sum;
    };
    T *operator[](int index)
    {
        if(index >= _length || index<0){
            throw (std::out_of_range("out_of_range"));
        }
        return _arr[index];
    };
};

#endif