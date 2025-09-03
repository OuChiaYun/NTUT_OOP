#ifndef DRINK_H
#define DRINK_H

#include <string>
#include <vector>
#include "topping.h"

class Drink
{
public:
    void con(std::string name, double sweetness_level, int price)
    {
        if (!(0 <= sweetness_level && sweetness_level <= 1))
        {
            throw std::string("Sweetness level should be between [0, 1].");
        }
        if (!(0 <= price))
        {
            throw std::string("Price should be between [0, inf).");
        }
        if (name.length() < 4)
        {
            throw std::string("The length of topping name should longer than 4.");
        }
        _name = name;
        _sweetness_level = sweetness_level;
        _price = price;
    }

    Drink() = default;

    /* The constructor of the Drink. */
    Drink(std::string name, double sweetness_level, int price)
    {
        con(name, sweetness_level, price);
    }

    /* The destructor of the Drink. */
    ~Drink() {}

    /* Return the name of drink. */
    std::string getName() const
    {
        if (_name == "")
        {
            throw std::string("name is empty");
        }
        return _name;
    }

    /* Return the level of sweetness. */
    double getSweetnessLevel() const
    {
        if (_sweetness_level == -1)
        {
            throw std::string("sweetness_level is empty");
        }
        return _sweetness_level;
    }

    /* Return the price of drink. */
    int getPrice() const
    {
        if (_price == -1)
        {
            throw std::string("price is empty");
        }
        return _price;
    }

    /* Add a topping to the drink. */
    void addTopping(Topping topping)
    {
        if (_sweetness_level == -1)
        {
            _sweetness_level = -1;
        }

        if (_price == -1)
        {
            _price = -1;
        }

        if(_sweetness_level != -1 && _price != -1)
        {
            _sweetness_level += topping.getSweetnessLevel();
            _price += topping.getPrice();
        }
        _topping.push_back(topping);
    }

    /* Get the topping of drink by index, the index is determine by the order of topping added and start from 0. */
    Topping getToppingByIndex(int index) const
    {
        if (index >= _topping.size() || index < 0)
        {
            throw std::string("out of range");
        }
        return _topping[index];
    }

    /* Get the count of topping in drink. */
    int getToppingCount() const
    {

        return _topping.size();
    }

    /* Operator overloading */
    Drink &operator=(const Drink &other)
    {
        if (this != &other)
        {
            con(other.getName(), other.getSweetnessLevel(), other.getPrice());
            this->_topping = other._topping;
        }
        return *this;
    }

private:
    /* Put some attribute on here if necessary. */
    string _name = "";
    double _sweetness_level = -1;
    int _price = -1;
    vector<Topping> _topping;
};

#endif
