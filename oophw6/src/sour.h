
#ifndef SOUR_H
#define SOUR_H

#include <iostream>
#include "alcohol.h"

using namespace std;

class Sour : public Alcohol
{

public:

    ~Sour() = default;
    Sour() = default;
    // Sour(const Sour &s)
    // {
    //     _name =s. _name;
    //     _price = s._price;
    //     _content = s._content;
    // }
    // Sour(const Alcohol &a) : Alcohol(a) {}

    // how to use The parameterized copy constructor

    Sour(string name, int price, double content) : Alcohol(name, price, content){}

    void dilute() override
    {
        _content = _content * 0.7;
    };
    Sour operator+(const Sour &other)
    {
        // Combine two sours into one sour.
        // The name  of the combined sour should be the name of the first sour.
        int _p = this->_price + other._price;
        // The price of the combined sour should be the sum of two sours.
        double _c = (this->_content + other._content) / 2;
        // The content of the combined sour should be the average content of two sours.
        return Sour(this->_name, _p, _c);
    };

    bool operator==(const Sour &other)
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
    Sour &operator=(const Sour &other)
    {
        // cout << "u" << endl;
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
