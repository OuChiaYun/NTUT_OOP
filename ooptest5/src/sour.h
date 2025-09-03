#ifndef SOUR_H
#define SOUR_H

#include <iostream>
#include <vector>
#include <string>
#include "alcohol.h"

using namespace std;

class Sour : public Alcohol
{

protected:
private:
    /* data */
public:
    Sour() : Alcohol(){};
    ~Sour() = default;

    Sour(string name, int price, double content) : Alcohol(name, price, content) {}

    void dilute() override
    {
        _content = _content * 0.7;
    }

    Sour operator+(const Sour &other)
    {
        // if (this != &other)
        // {

        double c = (this->_content + other._content) / 2;
        int p = this->_price + other._price;
        Sour s(this->_name, p, c);
        return s;
        // }
        // else
        // {
        // return *this;
        // }
    };

    bool operator==(const Sour &other)
    {
        // if (this == &other)
        // {
        //     return true;
        // }

        if (this->_name == other._name || this->_content == other._content || this->_price == other._price)
        {
            return true;
        }

        return false;
    }
    Sour &operator=(const Sour &other)
    {
        this->_name = other._name;
        this->_content = other._content;
        this->_price = other._price;
        return *this;
    }
};

#endif