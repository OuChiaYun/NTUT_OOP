#include <iostream>
#include <set>
using namespace std;
int main()
{
    printf("----------------------------------------------\n");
    // 宣告整數 set
    set<int> numSet;

    // 新增元素
    numSet.insert(1);
    numSet.insert(6);
    numSet.insert(8);

    // 檢查 set 是否包含指定元素
    set<int>::iterator iter;
    iter = numSet.find(6);
    if (iter != numSet.end())
    {
        cout << "Found: " << *iter << endl;
    }
    else
    {
        cout << "Not found." << endl;
    }
    printf("----------------------------------------------\n");

    // 以迴圈逐一處理 set 中的每個元素
    cout << "All elements:" << endl;
    for (iter = numSet.begin(); iter != numSet.end(); iter++)
    {
        cout << *iter << endl;
    }

    printf("----------------------------------------------\n");

    ////////////////////////////////////////////////////////////////////////////////////

    // 第一種初始化方式
    set<int> numSet1;
    numSet1.insert(1);
    numSet1.insert(6);
    numSet1.insert(8);

    // 第二種初始化方式
    set<int> numSet2{1, 6, 8};

    // 第三種初始化方式
    int arr[] = {1, 6, 8};
    set<int> numSet3(arr, arr + 3);

    printf("----------------------------------------------\n");
    ///////////////////////////////////////////////////////////////////////////////////////

    set<int> numSet4;

    // 新增元素
    numSet4.insert(1);
    numSet4.insert(6);
    numSet4.insert(8);

    // 刪除元素
    numSet4.erase(6);

    // 以迴圈逐一處理 set 中的每個元素
    set<int>::iterator iter2;
    cout << "All elements:" << endl;
    for (iter2 = numSet4.begin(); iter2 != numSet4.end(); iter2++)
    {
        cout << *iter2 << endl;
    }

    printf("----------------------------------------------\n");
    ///////////////////////////////////////////////////////////////////////////////////////

    set<int> numSet5{1, 6, 8};

    // 清空所有元素
    numSet5.clear();

    // 取得 set 內部元素個數
    cout << "Number of elements: " << numSet5.size() << endl;

    // 檢查 set 是否是空的
    if (numSet5.empty())
    {
        cout << "numSet is empty." << endl;
    }

    printf("----------------------------------------------\n");
    ///////////////////////////////////////////////////////////////////////////////////////

    return 0;
}