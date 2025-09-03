#ifndef HONEY_H
#define HONEY_H

#include <iostream>
#include "cake.h"

using namespace std;

class HoneyCake : public Cake
{

private:
    static int count;

public:

    HoneyCake():Cake(){
        count++;
    };

    HoneyCake(int price, int sweet) : Cake(price,sweet)
    {
        count++;
    };
    ~HoneyCake()override{
        count--;
        Cake::count--;
    }
    std::string to_string()
    {
        char buf[256] = {'0'};
        sprintf(buf, "| HoneyCake            |         %-3d|         %-3d|", _price, _sweet);
        // string b= buf;
        return buf;
    };
    static int get_count(){
        return count;
    };
};

int HoneyCake::count = 0;

#endif