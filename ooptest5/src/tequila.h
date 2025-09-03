#ifndef TEQUILA_H
#define TEQUILA_H

#include <iostream>
#include <vector>
#include <string>
#include "alcohol.h"

using namespace std;

class Tequila : public Alcohol
{
private:
    /* data */
public:
    Tequila() : Alcohol(){};
    ~Tequila() = default;

    Tequila(string name, int price, double content) : Alcohol(name, price, content) {}

    void dilute() override
    {
        _content = _content * 0.95;
    };

    Tequila operator+(const Tequila &other)
    {

        // if (this != &other)
        // {

        double c = (this->_content + other._content) / 2;
        int p = this->_price + other._price;
        Tequila t(this->_name, p, c);
        return t;
        // }
        // else
        // {
        //     return *this;
        // }
    }
    bool operator==(const Tequila &other)
    {
        if (this == &other)
        {
            return true;
        }

        if (this->_name == other._name || this->_content == other._content || this->_price == other._price)
        {
            return true;
        }

        return false;
    }

    // Tequila &operator=(const Tequila &other){
    //         return Tequila("bbbb", 1, 0.3);
    // }
};

#endif