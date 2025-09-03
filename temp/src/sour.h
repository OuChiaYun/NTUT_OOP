
#ifndef SOUR_H
#define SOUR_H

#include <iostream>
#include "alcohol.h"

using namespace std;

class Sour : public Alcohol
{

    // private:
    //     string _name = "";
    //     int _price = -1;
    //     double _content = -1;
public:
    void init(string name, int price, double content)
    {

 
        _name = name;
        _price = price;
        _content = content;
    }

    ~Sour() = default;
    Sour() = default;
    Sour(const Sour &s)
    {
        // cout << s._name << s._price << s._content << endl;
        init(s._name, s._price, s._content);
    }
    Sour(const Alcohol &a) : Alcohol(a) {}

    // how to use The parameterized copy constructor

    Sour(string name, int price, double content) : Alcohol(name, price, content)
    {
        init(name, price, content);
    }

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
