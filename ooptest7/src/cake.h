#ifndef CAKE_H
#define CAKE_H


class Cake
{
protected:
    int _price = -1;
    int _sweet = -1;
public:
    Cake() = delete;
    virtual ~Cake(){};
    Cake(int price, int sweet){

    };

};


#endif