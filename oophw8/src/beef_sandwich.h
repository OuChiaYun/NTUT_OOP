#ifndef BEEF_SANDWICH_H
#define BEEF_SANDWICH_H

#include <iostream>
#include <set>
#include "sandwich.h"

using namespace std;

class BeefSandwich : public Sandwich
{

private:
    static set<int> _id_record;
    static int _size;

public:
    ~BeefSandwich()
    {
        // Sandwich::_size--;
        Sandwich::_id_record.erase(_id);
        //        BeefSandwich::_size--;
        BeefSandwich::_id_record.erase(_id);
    }
    BeefSandwich(int price, int id) : Sandwich(price, id)
    {

        //        BeefSandwich::_size++;
        _id_record.insert(id);
    };
    static bool record_has_specific_id(int id)
    {

        if (BeefSandwich::_id_record.find(id) != _id_record.end())
        {
            return true;
        }
        return false;
    }
    static int get_size_of_record_container()
    {
        return BeefSandwich::_id_record.size();
    }
};

set<int> BeefSandwich::_id_record = {};
// int        BeefSandwich::_size = 0;

#endif