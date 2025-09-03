
#ifndef ALCOHOL_H
#define ALCOHOL_H

#include <iostream>

using namespace std;

// has vitural destructure

class Alcohol
{

protected:
    string _name = "";
    int _price = -1;
    double _content = -1;

public:
    void init(string name, int price, double content)
    {

        if (name.length() == 0)
        {

            throw std::invalid_argument("The length of name should longer than 0.");
        }
        if (!(0 < price))
        {

            throw std::invalid_argument("Price should be between [0, inf).");
        }
        if (!(0 <= content && content <= 1))
        {
            throw std::invalid_argument("Content should be between [0, 1].");
        }
        _name = name;
        _price = price;
        _content = content;
    }

    virtual ~Alcohol() = default;

    Alcohol() = default;
    Alcohol(const Alcohol &alc)
    {
        cout <<"b" << endl;
        init(alc._name, alc._price, alc._content);
    };

    Alcohol(string name, int price, double content)
    {
        init(name, price, content);
    }

    virtual void dilute() = 0; // pure virtual function // practice in subclass

    double get_alcohol_content()
    {
        if (_content < 0)
        {
            throw std::invalid_argument("Content should be between [0, 1].");
        }

        return _content;
    };

    int get_price()
    {
        if (_price < 0)
        {
            throw std::invalid_argument("Price should be between [0, 1].");
        }

        return _price;
    };
    string get_name()
    {
        if (_name.length() == 0)
        {
            throw std::invalid_argument("The length of name should longer than 0.");
        }

        return _name;
    };
};

#endif
