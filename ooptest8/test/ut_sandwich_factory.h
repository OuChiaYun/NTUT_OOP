#include <iostream>
#include <vector>
#include "../src/sandwich_factory.h"
#include "../src/sandwich.h"
#include "../src/sweet_sandwich.h"
using namespace std;

TEST(SANDWICHFACTORY, test_create_sandwich_should_return_price_and_id)
{
    SweetSandwich *sw1 = new SweetSandwich(15, 0);
    // SandwichFactory st;
    SweetSandwich *sw2 = SandwichFactory<SweetSandwich>::create_sandwich(15, 0);
    ASSERT_EQ(sw2->get_price(), 15);
    ASSERT_EQ(sw2->get_id(), 0);
    delete sw1;
    delete sw2;
};

TEST(SANDWICHFACTORY, test_create_sandwich_array_should_return_price_and_id)
{
    vector<SweetSandwich *> sweet_sandwich_set = SandwichFactory<SweetSandwich>::create_sandwich_array(15, 5, {33, 44, 55, 66, 99});
    ASSERT_EQ(sweet_sandwich_set[0]->get_price(), 15);
    ASSERT_EQ(sweet_sandwich_set[0]->get_id(), 33);
    for(int i = 0;i<sweet_sandwich_set.size();i++){
        delete sweet_sandwich_set[i];
    }
};

TEST(SANDWICHFACTORY, test_create_sandwich_array_should_return_invalid_argument)
{
    
    ASSERT_THROW(SandwichFactory<SweetSandwich>::create_sandwich_array(15, -5, {33, 44, 55, 66, 99}),std::invalid_argument);
};
