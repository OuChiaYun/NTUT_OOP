#ifndef ALCOHOL_H
#define ALCOHOL_H

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class Alcohol
{
protected:
    string _name = "";
    int _price = -1;
    double _content = -1;
    /* data */
public:
    Alcohol(){};
    virtual ~Alcohol(){};

    Alcohol(string name, int price, double content)
    {
        if ((name == "") || (price < 0) || (content < 0) || (content > 1))
        {
            throw std::invalid_argument("wrong");
        }
        _name = name;
        _price = price;
        _content = content;
    };
    virtual void dilute() = 0;

    double get_alcohol_content()
    {

        if (_content < 0 || _content > 1)
        {
            throw std::invalid_argument("wrong");
        }
        return _content;
    }

    int get_price()
    {

        if (_price < 0)
        {
            throw std::invalid_argument("wrong");
        }
        return _price;
    }

    string get_name()
    {
        if (_name == "")
        {
            throw std::invalid_argument("wrong");
        }
        return _name;
    }
};

#endif