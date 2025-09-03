#ifndef PRODUCT_H
#define PRODUCT_H

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Product{

    private:

        string  _name = "";
        int _price = 0;

    public:
        ~Product() = default;
        Product() = default;
        Product(string name,int price){
            if(name.length() < 4 || price <0){
                throw(std::string("wrong value"));
            }

            _name = name;
            _price = price;
        };

        string getName()const{
            return _name;
        };
        int getPrice() const{
            return _price;
        };

        Product& operator=(const Product& other){
            if (this != & other){
                this->_name = other.getName();
                this->_price = other.getPrice();
            }

            return *this;
        };
        bool operator==(const Product& other){
            if (this != & other){

                if(this->_name == other.getName()){
                    return true;
                }else{
                    return false;
                }
            }
            return true;
        };

};

#endif