#include <set>
#include <iostream>

using namespace std;

int main()
{

    set<int> s;

    // 元素插入
    s.insert(5);
    s.insert(6);
    s.insert(7);
    s.insert(8);
    s.insert(9);
    s.insert(0);

    // 中序遍歷: (use iterator)

    set<int>::iterator it;
    for (it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;

    set<int>::reverse_iterator rit;
    for (rit = s.rbegin(); rit != s.rend(); rit++)
    {
        cout << *rit << " ";
    }

    cout << endl;

    // erase() 元素刪除
    s.erase(5);
    for (it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;

    s.clear();

    // 元素查找(find)，找到返回該值跌代器位置
    it = s.find(6);
    cout << *it << endl;

    // 元素個數
    cout << s.size() << endl;

    // set 是否為空

    cout << s.empty() << endl;
}