#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <iostream>
#include <vector>
#include <string>
#include "Product.h"

using namespace std;

class ShoppingCart
{

private:
    int _item_list_size = 0;
    // Product* _item_list;

    vector<Product> _vitem;

public:
    ~ShoppingCart() = default;
    ShoppingCart() = default;
    ShoppingCart(int item_list_size, Product *item_list)
    {
        _item_list_size = item_list_size;
        // _item_list = item_list;
        // cout << "hi " << _item_list[0].getPrice() << endl;

        for (int i = 0; i < _item_list_size - 1; i++)
        {
            for (int j = i + 1; j < _item_list_size; j++)
            {
                if (item_list[i].getName() == item_list[j].getName())
                {
                    throw(string("same product"));
                }
            }
        }

        for (int i = 0; i < _item_list_size; i++)
        {
            _vitem.push_back(item_list[i]);
        }
    };

    int getItemCount() const
    {
        return _item_list_size;
    };
    Product getItemByIndex(int index)
    {
        if (index >= _item_list_size || index < 0)
        {
            throw(std::string{"wrong index"});
        }

        // return _item_list[index];
        return _vitem[index];
    };

    void setItemByIndex(int index, Product product)
    {

        if (index >= _vitem.size() || index < 0)
        {
            throw(std::string{"wrong index"});
        }

        for (int i = 0; i < _item_list_size; i++)
        {
            if (_vitem[i].getName() == product.getName())
            {
                throw(std::string("same product"));
            }
        }

        // _item_list[index] = product;

        _vitem[index] = product;
        cout << "ooo" << _vitem[index].getName() << endl;
    };
    void appendItem(Product product)
    {

        for (int i = 0; i < _item_list_size; i++)
        {
            if (_vitem[i].getName() == product.getName())
            {
                throw(std::string("same product"));
            }
        }

        _item_list_size++;
        _vitem.push_back(product);
    };

    int getTotalCost() const
    {
        int count = 0;
        for (int i = 0; i < _item_list_size; i++)
        {
            // count += _item_list[i].getPrice();
            count += _vitem[i].getPrice();
        }
        cout << count << endl;
        return count;
    };

    ShoppingCart &operator+(const ShoppingCart &other)
    {

        if (this == &other)
        {
            // this->_vitem.clear();
            // this->_item_list_size = 0;
            return *this;
        }
        else
        {
            vector<Product> tmp = this->_vitem;
            // for(int i = 0;i<_item_list_size;i++){
            //     tmp.push_back(this->_vitem[i]);
            // }
            int count = this->_item_list_size + other._item_list_size;
            // int count = 0;
            int flag = 0;

            for (int i = 0; i < other._item_list_size; i++)
            {
                flag = 0;
                for (int j = 0; j < this->_item_list_size; j++)
                {
                    if (this->_vitem[j].getName() == other._vitem[i].getName())
                    {
                        flag = 1;
                    }
                }

                if (flag == 0)
                {
                    count--;
                    tmp.push_back(other._vitem[i]);
                    cout << "oo " << tmp[i].getName() << "kk" << endl;
                }
            }
            this->_vitem.clear();
            this->_vitem = tmp;
            this->_item_list_size = tmp.size();

            return *this;
        }
    };

    ShoppingCart &operator-(const ShoppingCart &other)
    {

        if (this == &other)
        {
            this->_vitem.clear();
            this->_item_list_size = 0;
            return *this;
        }
        else
        {
            vector<Product> tmp;
            int count = 0;
            int flag = 0;
            for (int i = 0; i < this->_item_list_size; i++)
            {
                flag = 0;
                for (int j = 0; j < other._item_list_size; j++)
                {
                    if (this->_vitem[i].getName() == other._vitem[j].getName())
                    {
                        flag = 1;
                    }
                }
                if (flag == 0)
                {
                    count++;
                    tmp.push_back(this->_vitem[i]);
                }
            }
            this->_vitem.clear();
            this->_vitem = tmp;
            this->_item_list_size = count;

            return *this;
        }
    };
    ShoppingCart &operator=(const ShoppingCart &other)
    {

        if (this != &other)
        {
            this->_vitem.clear();
            this->_vitem = other._vitem;
            this->_item_list_size = other._item_list_size;
        }

        return *this;
    };
};

#endif
