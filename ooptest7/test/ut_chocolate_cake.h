#include<iostream>
#include<string.h>
#include "../src/chocolate_cake.h"

using namespace std;

TEST(CHOCOLATE_CAKE,constructor){
    ChocolateCake cho(1,2);
    ASSERT_EQ(cho.get_price(),1);
    ASSERT_EQ(cho.get_sweet(),2);
};

TEST(CHOCOLATE_CAKE,get_count){
    ChocolateCake cho1(1,2);
    ChocolateCake cho2(2,2);
    ChocolateCake cho3;
    ASSERT_EQ(ChocolateCake::get_count(),3);
};
       
TEST(CHOCOLATE_CAKE,to_string){
    ChocolateCake cho(11,22);
    string str = "| ChocolateCake        |         11 |         22 |";
    // cout << cho.to_string();
    ASSERT_EQ(cho.to_string(),str);
};