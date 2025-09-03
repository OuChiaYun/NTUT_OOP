#ifndef SWEET_SANDWICH_H
#define SWEET_SANDWICH_H


#include <iostream>
#include <set>
#include "sandwich.h"

using namespace std;

class SweetSandwich : public Sandwich
{
private:
    static set<int> _id_record ;
    // static int _size;
public:
    ~SweetSandwich(){
        // Sandwich::_size--;
        Sandwich::_id_record.erase(_id);
        // SweetSandwich::_size--;
        SweetSandwich::_id_record.erase(_id);
    }
    SweetSandwich(int price, int id):Sandwich(price,id) {
        // SweetSandwich::_size++;
        _id_record.insert(id);
    }

    static bool record_has_specific_id(int id) {

        if(SweetSandwich::_id_record.find(id) != _id_record.end()){
            return true;
        }
        return false;
    }

    static int get_size_of_record_container() {
        return SweetSandwich::_id_record.size();
    }
};

set<int> SweetSandwich::_id_record = {};
// int SweetSandwich::_size = 0;

#endif