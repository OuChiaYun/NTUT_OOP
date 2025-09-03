#ifndef SANDWICH_H
#define SANDWICH_H

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Sandwich
{

protected:
    int _price = 0;
    int _id = 0;

// private:
    //static int _size;
    // static int _size;
    static set<int> _id_record;

public:
    virtual ~Sandwich() = default;
    Sandwich() = default;
    Sandwich(int price, int id)
    {
        if(price < 0){
            throw std::invalid_argument("wrong");
        }
        _price = price;
        _id = id;
        _id_record.insert(id);
        // _size++;
    }
    int get_price()
    {
        return _price;
    }

    int get_id()
    {
        return _id;
    }

    static bool record_has_specific_id(int id)
    {

        if(_id_record.find(id) != _id_record.end()){
            return true;
        }
        return false;
    }

    static int get_size_of_record_container()
    {
        return _id_record.size();
    }
};


set<int> Sandwich::_id_record = {};
// int Sandwich::_size = 0;

#endif