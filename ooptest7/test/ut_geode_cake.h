#include<iostream>
#include<string.h>
#include "../src/geode_cake.h"

using namespace std;

TEST(GEODE_CAKE,constructor){
    GeodeCake geo(1,2);
    ASSERT_EQ(geo.get_price(),1);
    ASSERT_EQ(geo.get_sweet(),2);
};
       
TEST(GEODE_CAKE,get_count){
    GeodeCake geo1(1,2);
    GeodeCake geo2;
    ASSERT_EQ(GeodeCake::get_count(),2);
};

TEST(GEODE_CAKE,to_string){
    GeodeCake geo(11,22);
    string str = "| GeodeCake            |         11 |         22 |";
    // cout << cho.to_string();
    ASSERT_EQ(geo.to_string(),str);
};