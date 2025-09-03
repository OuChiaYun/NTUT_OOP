#include<iostream>
#include "../src/chocolate_cake.h"
#include "../src/geode_cake.h"
using namespace std;

TEST(CAKE,test_cake_constructor_should_return_price_and_sweet){
    ChocolateCake cho(1,2);
    ASSERT_EQ(cho.get_price(),1);
    ASSERT_EQ(cho.get_sweet(),2);
};

TEST(CAKE,test_cake_constructor_should_return_count_number){
    ChocolateCake cho1(1,2);
    ChocolateCake cho2(3,4);
    ChocolateCake cho4;
    Cake * cake = new ChocolateCake(3,4);
    GeodeCake geo(11,22);
    ASSERT_EQ(Cake::get_total(),5);
    ASSERT_EQ(ChocolateCake::get_count(),4);
    delete cake;
};