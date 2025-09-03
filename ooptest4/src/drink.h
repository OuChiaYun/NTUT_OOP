#ifndef DRINK_H
#define DRINK_H

#include <iostream>
#include <vector>
#include <string>
#include "topping.h"

using namespace std;

class Drink
{

private:
    string _name = "";
    double _sweetness_level = -1;
    double _price = -1;
    vector<Topping> _topping;

public:
    void ini(string name, double sweetness_level, double price)
    {
        if (!(0 <= sweetness_level && sweetness_level <= 1))
        {
            throw std::string("Sweetness level should be between [0, 1].");
        }

        if (name.length() < 4)
        {

            throw std::string("The length of topping name should longer than 4.");
        }

        if (price < 0)
        {
            throw std::string("Sweetness level should be between [0, int].");
        }

        _name = name;
        _sweetness_level = sweetness_level;
        _price = price;
    }

    ~Drink() = default;
    Drink() = default;

    Drink(string name, double sweetness_level, double price)
    {
        ini(name, sweetness_level, price);
    }

    string getName()
    {
        if (_name == "")
        {
            throw(std::string("name is empty "));
        }

        return _name;
    }

    double getSweetnessLevel()
    {
        if (_sweetness_level < 0)
        {
            throw(std::string("sweet is empty"));
        }

        return _sweetness_level;
    }

    double getPrice()
    {
        if (_price < 0)
        {
            throw(std::string("price is empty"));
        }
        return _price;
    }

    void addTopping(Topping topping)
    {
        if (_sweetness_level < 0 || _name == "" || _price < 0)
        {
            throw(string("empty"));
        }

        _sweetness_level += topping.getSweetnessLevel();
        _price += topping.getPrice();
        _topping.push_back(topping);
    }
    Topping getToppingByIndex(int index)
    {
        if (index >= _topping.size() || index < 0)
        {
            throw(std::string("index is wromg"));
        }
        return _topping[index];
    }
    int getToppingCount()
    {
        return _topping.size();
    }
    Drink operator=(const Drink &other)
    {
        if (this != &other)
        {
            ini(other._name, other._sweetness_level, other._price);
            this->_topping = other._topping;
        }
        return *this;
    }


    //////////////////////

    Drink operator+(const Drink &other)
    {
        if (this != &other)
        {
            ini(other._name, other._sweetness_level+this->_sweetness_level, other._price+this->_price);
            this->_topping = other._topping;
        }
        return *this;
    }
};

#endif