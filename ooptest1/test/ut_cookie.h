#include<iostream>
#include"../src/cookie.h"


using namespace std;

TEST(COOKIE,nis_postive){

    int arr[4] = {1,2,3,4};
    
    int ans = func(4,arr);

    ASSERT_EQ(ans,6);
    
    arr[0] = 9;
    ans = func(4,arr);

    ASSERT_EQ(ans,12);
};

TEST(COOKIE,nis_nrgative){

    int arr[4] = {1,2,3,4};
    int ans = func(-4,arr);

    ASSERT_EQ(ans,-1);

};

TEST(COOKIE,arris_nrgative){

    int arr[4] = {1,2,-3,4};
    
    int ans = func(4,arr);

    ASSERT_EQ(ans,-1);
};