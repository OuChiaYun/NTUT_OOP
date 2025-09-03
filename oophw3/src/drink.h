#include <string>
#include<vector>


using namespace std;

class Drink{

private:
    string _name ;
    double _sweetness_level ;
    vector<string> _topping_string;

public:
    /* The constructor of the Drink. */

    Drink (){
        _name = "nul";
        _sweetness_level = -1;
    }
    Drink(std::string name, double sweetness_level){

        if (name.length() <4 ){
            throw std::string("name is empty");
        }
        if (sweetness_level < 0 || sweetness_level > 1){
            throw std::string("sweetness_level is empty");
        }
        _name = name;
        _sweetness_level = sweetness_level;

    }
    /* The destructor of the Drink. */
    ~Drink(){
        // delete vector<sring>
        _topping_string.clear();
        _topping_string.shrink_to_fit();
        // cout << "ff"<<topping_string.capacity() << endl;

    }
    /* Return the name of drink. */
    std::string getName(){
        if (_name ==  "nul"){
            throw std::string("name is empty");
        }

        return _name;

    }
    /* Return the level of sweetness. */
    double getSweetnessLevel(){
        if (_sweetness_level == -1){
            throw std::string("sweetness_level is empty");
        }
        return _sweetness_level;

    }
    /* Add a topping to the drink. */
    void addTopping(std::string topping){
        _topping_string.push_back(topping);
        // cout << topping_string<<endl;
    }


    /* Get the topping of drink by index, the index is determine by the order of topping added and start from 0. */
    std::string getToppingByIndex(int index){

        if (index >= _topping_string.size() || index <0){
            throw std::string("out of range");
        }

        // cout << topping_string[index] << endl;
        return _topping_string[index];
    }
    /* Get the count of topping in drink. */
    int getToppingCount(){
        return _topping_string.size();
    }
    // private:
    /* Put some attribute on here if necessary. */
};
