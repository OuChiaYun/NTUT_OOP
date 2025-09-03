
#ifndef TEQUILA_H
#define TEQUILA_H

#include <iostream>
#include "alcohol.h"

using namespace std;

class Tequila : public Alcohol
{
public:
    ~Tequila() = default;
    Tequila() = default;
    Tequila(string name, int price, double content) : Alcohol(name, price, content){}

    Tequila(const Tequila &t)
    {
        _name =t._name;
        _price = t._price;
        _content = t._content;
    }
    Tequila(const Alcohol &a) : Alcohol(a) {}    

    void dilute() override
    {
        _content = _content * 0.95;
    }
    Tequila operator+(const Tequila &other)
    {

        // Combine two sours into one sour.
        // The name  of the combined sour should be the name of the first sour.
        int _p = this->_price + other._price;
        // The price of the combined sour should be the sum of two sours.
        double _c = (this->_content + other._content) / 2;
        // The content of the combined sour should be the average content of two sours.
        return Tequila(this->_name, _p, _c);
    };
    
    bool operator==(const Tequila &other)
    {

        if (((this->_name == other._name) && (this->_price == other._price) && (this->_content == other._content)))
        {
            return true;
        }
        else
        {
            return false;
        }
    };
    Tequila &operator=(const Tequila &other)
    {
        if (this != &other)
        {
            this->_name = other._name;
            this->_price = other._price;
            this->_content = other._content;
        }

        return *this;
    };
};

#endif
