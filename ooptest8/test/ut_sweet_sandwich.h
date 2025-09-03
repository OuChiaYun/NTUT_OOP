#include<iostream>
#include "../src/sandwich.h"
#include "../src/sweet_sandwich.h"

using namespace std;

TEST(SWEETSANDWICH,test_constructor_should_return_price_and_id){
    Sandwich* sw1 = new SweetSandwich(15, 0);
    ASSERT_EQ(sw1->get_price(),15);
    ASSERT_EQ(sw1->get_id(),0);
    delete sw1;
};

TEST(SWEETSANDWICH, test_constructor_should_return_invalid_argument)
{
    ASSERT_THROW(SweetSandwich sw(-15, 0), std::invalid_argument);
};

TEST(SWEETSANDWICH, record_has_specific_id_return_true){
    Sandwich* sw1 = new SweetSandwich(15, 0);
    ASSERT_TRUE(SweetSandwich::record_has_specific_id(0));
    delete sw1;
};

TEST(SWEETSANDWICH, record_has_specific_id_return_false){
    Sandwich* sw1 = new SweetSandwich(15, 0);
    ASSERT_FALSE(SweetSandwich::record_has_specific_id(1));
    delete sw1;

};


TEST(SWEETSANDWICH,test_get_size_of_record_container_should_return_size){
    Sandwich* sw1 = new SweetSandwich(15, 1);
    ASSERT_EQ(SweetSandwich::get_size_of_record_container(),1);
    delete sw1;

};

