#include<iostream>
#include<string.h>
#include "../src/honey_cake.h"

using namespace std;

TEST(HONEY_CAKE,constructor){
    HoneyCake hon(1,2);
    ASSERT_EQ(hon.get_price(),1);
    ASSERT_EQ(hon.get_sweet(),2);
};
       
TEST(HONEY_CAKE,get_count){
    HoneyCake hon1(1,2);
    HoneyCake hon2;
    ASSERT_EQ(HoneyCake::get_count(),2);
};

TEST(HONEY_CAKE,to_string){
    HoneyCake hon(11,22);
    string str = "| HoneyCake            |         11 |         22 |";
    // cout << cho.to_string();
    ASSERT_EQ(hon.to_string(),str);
};