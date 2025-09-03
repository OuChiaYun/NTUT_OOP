#ifndef GEODE_CAKE_H
#define GEODE_CAKE_H

#include <iostream>
#include "cake.h"

using namespace std;

class GeodeCake : public Cake
{

private:
    static int count;

public:
    GeodeCake():Cake(){
        count++;
    };
    GeodeCake(int price, int sweet) : Cake(price, sweet)
    {
        count++;
    };
    ~GeodeCake()
    {
        count--;
        Cake::count--;
    }
    std::string to_string()
    {
        char buf[256] = {'0'};
        sprintf(buf, "| GeodeCake            |         %-3d|         %-3d|", _price, _sweet);
        // string b= buf;
        return buf;
    };
    static int get_count(){
        return count;
    };
};

int GeodeCake::count = 0;

#endif