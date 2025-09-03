#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Drink
{

private:
    string _name = "";
    double _sweetness_level = 0;
    vector<string> _topping;

public:
    void ini(string name, double sweetness_level)
    {
        if (!(0 <= sweetness_level && sweetness_level <= 1))
        {
            throw std::string("Sweetness level should be between [0, 1].");
        }

        if (name.length() < 4)
        {

            throw std::string("The length of topping name should longer than 4.");
        }

        _name = name;
        _sweetness_level = sweetness_level;
 
    }
    ~Drink() = default;
    Drink() = default;
    Drink(string name, double sweetness_level)
    {
        ini(name, sweetness_level);
    }

    string getName()
    {
        if (_name == "")
        {
            throw(string("empty"));
        }

        return _name;
    }

    double getSweetnessLevel()
    {
        if (_sweetness_level == 0)
        {
            throw(string("empty"));
        }

        return _sweetness_level;
    }

    void addTopping(string topping){

        _topping.push_back(topping);

    }

    string getToppingByIndex(int n)
    {
        if(n >= _topping.size() || n<0){
            throw(string("wrong"));
        }

        return _topping[n];

    }

    int getToppingCount(){
        return _topping.size();
    }


};

// vec[i] - 存取索引值為 i 的元素值。
// vec.at(i) - 存取索引值為 i 的元素的值，
// vec.front() - 回傳 vector 第一個元素的值。
// vec.back() - 回傳 vector 最尾元素的值。

// vec.push_back() - 新增元素至 vector 的尾端，必要時會進行記憶體配置。
// vec.pop_back() - 刪除 vector 最尾端的元素。
// vec.insert() - 插入一個或多個元素至 vector 內的任意位置。
// vec.erase() - 刪除 vector 中一個或多個元素。
// vec.clear() - 清空所有元素。

// vec.empty() - 如果 vector 內部為空，則傳回 true 值。
// vec.size() - 取得 vector 目前持有的元素個數。
// vec.resize() - 改變 vector 目前持有的元素個數。
// vec.capacity() - 取得 vector 目前可容納的最大元素個數。這個方法與記憶體的配置有關，它通常只會增加，不會因為元素被刪減而隨之減少。
// 重新配置／重設長度
// vec.reserve() - 如有必要，可改變 vector 的容量大小（配置更多的記憶體）。在眾多的 STL 實做，容量只能增加，不可以減少