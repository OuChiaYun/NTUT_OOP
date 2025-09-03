#ifndef CAKE_H
#define CAKE_H

#include<iostream>

using namespace std;

class Cake{

    // private:
    //     static int count;
    protected:
        static int count;
        int _price = 0;
        int _sweet = 0;
    public:
        virtual ~Cake() = default;
        Cake(){
            count++;
        };
        Cake(int price, int sweet){
            _price = price;
            _sweet = sweet;
            count++;
            // printf("cc %d \n",count);
        };
        int get_price(){
            return _price;
        };
        int get_sweet(){
            return _sweet;
        };
        static int get_total(){
            return count;
        };
        virtual std::string to_string() = 0;
};

int Cake::count = 0; 

#endif