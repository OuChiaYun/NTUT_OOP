#include <iostream>
#include <algorithm>
#include <vector>
#include <typeinfo>

using namespace std;

int main()
{

    vector<int> arr = {0, 1, 3, 5, 7, 7};
    vector<int> brr = {0, 2, 4, 6, 7, 7};

    vector<int> crr = {};

    printf("all 1: ");

    for (int i = 0; i < arr.size(); i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nall 2: ");
    for (int i = 0; i < brr.size(); i++)
    {
        printf("%d ", brr[i]);
    }

    printf("\nunion: "); // 並集
    set_union(arr.begin(), arr.end(), brr.begin(), brr.end(), back_inserter(crr));
    for (int i = 0; i < (crr.size()); i++)
    {
        printf("%d ", crr[i]);
    }

    vector<int> crr_2 = {};
    set_intersection(arr.begin(), arr.end(), brr.begin(), brr.end(), back_inserter(crr_2));

    printf("\nintersection: "); // 交集
    for (int i = 0; i < (crr_2.size()); i++)
    {
        printf("%d ", crr_2[i]);
    }

    vector<int> crr_3 = {};

    set_difference(arr.begin(), arr.end(), brr.begin(), brr.end(), back_inserter(crr_3));

    printf("\ndifference: "); // 差集
    for (int i = 0; i < (crr_3.size()); i++)
    {
        printf("%d ", crr_3[i]);
    }

    auto a = max_element(crr.begin(), crr.end());
    printf("\nmax: %d", *a);

    vector<int> drr = {};
    unique_copy(arr.begin(), arr.end(), back_inserter(drr)); // 刪除相鄰元素

    printf("\nuni: ");
    for (int i = 0; i < (drr.size()); i++)
    {
        printf("%d ", drr[i]);
    }

    vector<int> frr = {};
    reverse_copy(arr.begin(), arr.end(), back_inserter(frr));

    printf("\nrev: ");
    for (int i = 0; i < (frr.size()); i++)
    {
        printf("%d ", frr[i]);
    }

    auto g = count(arr.begin(), arr.end(), 7);

    printf("\ncount (7) : %ld", g);

}
