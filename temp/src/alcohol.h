
#ifndef ALCOHOL_H
#define ALCOHOL_H

#include <iostream>

using namespace std;

// has vitural destructure

class Alcohol
{
    // private:   
    public:     
        string _name = "";
        int _price = -1;
        double _content = -1;
// // 
    // public:
        void init(string name, int price, double content)
        {

            if (name.length() == 0)
            {

                throw std::string("The length of name should longer than 0.");
            }
            if (!(0 < price))
            {

                throw std::string("Price should be between [0, inf).");
            }
            if (!(0 <= content && content <= 1))
            {
                throw std::string("Content should be between [0, 1].");
            }
            _name = name;
            _price = price;
            _content = content;
        }

        virtual ~Alcohol() = default;

        Alcohol() = default;
        Alcohol(const Alcohol &alc)
        {
            // this->_name = alc._name;
            // this->_price = alc._price;
            // this->_content = alc._content;
            init(alc._name, alc._price, alc._content);
        };

        Alcohol(string name, int price, double content)
        {
            init(name, price, content);
        }

        virtual void dilute() = 0; // pure virtual function // practice in subclass

        double get_alcohol_content()
        {
            if (_content < 0)
            {
                throw std::string("Content should be between [0, 1].");
            }

            return _content;
        };

        int get_price()
        {
            if (_price < 0)
            {
                throw std::string("Price should be between [0, 1].");
            }

            return _price;
        };
        string get_name(){
            if (_name.length() == 0)
            {
                throw std::string("The length of name should longer than 0.");
            }

            return _name;
        };
};

#endif
