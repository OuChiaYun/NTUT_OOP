#ifndef DRINK_H
#define DRINK_H
#include <iostream>
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
        _arr = new Topping[100];
    }

    /* The destructor of the Drink. */
    ~Drink()
    {
        delete[] _arr;
    }

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
        // if (_sweetness_level == -1)
        // {
        //     _sweetness_level = -1;
        // }

        // if (_price == -1)
        // {
        //     _price = -1;
        // }

        _sweetness_level += topping.getSweetnessLevel();
        _price += topping.getPrice();

        if (n_cap <= n)
        {
            n_cap *= 2;
            Topping *_arr_tmp = new Topping[n_cap];

            for (int i = 0; i < n; i++)
            {
                _arr_tmp[i] = _arr[i];
            }
            _arr_tmp[n] = topping;

            delete[] _arr;
            _arr = _arr_tmp;
        }
        else
        {
            _arr[n] = topping;
        }
        n++;
        // cout << "rr " << _arr[n - 1].getName() << endl;
        // cout << n << endl;
    }

    /* Get the topping of drink by index, the index is determine by the order of topping added and start from 0. */
    Topping getToppingByIndex(int index) const
    {
        // cout << "pp " << _arr[0].getName() << index << endl;

        if (index >= n || index < 0)
        {
            throw std::string("out of range");
        }
        return _arr[index];
    }

    /* Get the count of topping in drink. */
    int getToppingCount() const
    {

        return n;
    }

    /* Operator overloading */
    Drink &operator=(const Drink &other)
    {
        if (this != &other)
        {
            con(other.getName(), other.getSweetnessLevel(), other.getPrice());

            if (this->_arr != nullptr)
            {
                delete[] this->_arr;
            }

            this->_arr = new Topping[other.n_cap];

            for (int i = 0; i < other.n; i++)
            {
                this->_arr[i] = other._arr[i];
            }
            this->n = other.n;
            this->n_cap = other.n_cap;
        }
        return *this;
    }

private:
    /* Put some attribute on here if necessary. */
    string _name = "";
    double _sweetness_level = -1;
    int _price = -1;
    // vector<Topping> _topping;
    Topping *_arr = nullptr;
    int n = 0;
    int n_cap = 100;
};

#endif
