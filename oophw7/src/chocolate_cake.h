#ifndef CHOCOLATE_CAKE_H
#define CHOCOLATE_CAKE_H

#include <iostream>
#include "cake.h"

using namespace std;

class ChocolateCake : public Cake
{

private:
    static int count;

public:
    ChocolateCake():Cake(){
        count++;
    };
    ChocolateCake(int price, int sweet) : Cake(price, sweet){
        count++;
        // printf("f%d \n",count);
    };
    std::string to_string()
    {
        
        char buf[256] = {'0'};
        sprintf(buf, "| ChocolateCake        |         %-3d|         %-3d|", _price, _sweet);
        // string b= buf;
        return buf;
    };
    ~ChocolateCake()override{
        count --;
        Cake::count--;
    };
    static int get_count(){
        return count;
    };
};

int ChocolateCake::count = 0;

#endif