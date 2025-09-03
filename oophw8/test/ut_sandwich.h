#include<iostream>
#include "../src/sandwich.h"
#include "../src/sweet_sandwich.h"
#include "../src/beef_sandwich.h"
using namespace std;

TEST(SANDWICH,test_constructor_should_return_price_and_id){
    Sandwich* sw1 = new SweetSandwich(15, 0);
    ASSERT_EQ(sw1->get_price(),15);
    ASSERT_EQ(sw1->get_id(),0);
    delete sw1;
};

TEST(SANDWICH, record_has_specific_id_return_true){
    Sandwich* sw1 = new SweetSandwich(15, 0);
    ASSERT_TRUE(Sandwich::record_has_specific_id(0));
    delete sw1;
};

TEST(SANDWICH, record_has_specific_id_return_false){
    Sandwich* sw1 = new SweetSandwich(15, 0);
    ASSERT_FALSE(Sandwich::record_has_specific_id(1));
    delete sw1;

};


TEST(SANDWICH,test_get_size_of_record_container_should_return_size){
    Sandwich* sw1 = new SweetSandwich(15, 1);
    BeefSandwich *bf1 = new BeefSandwich(30, 2);
    ASSERT_EQ(Sandwich::get_size_of_record_container(),2);
    delete sw1;
    delete bf1;

};

