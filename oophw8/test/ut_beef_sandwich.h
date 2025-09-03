#include <iostream>
#include "../src/sandwich.h"
#include "../src/beef_sandwich.h"
using namespace std;

TEST(BEEFSANDWICH, test_constructor_should_return_price_and_id)
{
    BeefSandwich *bf1 = new BeefSandwich(15, 0);
    ASSERT_EQ(bf1->get_price(), 15);
    ASSERT_EQ(bf1->get_id(), 0);
    delete bf1;
};

TEST(BEEFSANDWICH, test_constructor_should_return_invalid_argument)
{
    ASSERT_THROW(BeefSandwich bf(-15, 0), std::invalid_argument);
};

TEST(BEEFSANDWICH, record_has_specific_id_return_true)
{
    BeefSandwich *bf1 = new BeefSandwich(15, 0);
    ASSERT_TRUE(BeefSandwich::record_has_specific_id(0));
    delete bf1;
};

TEST(BEEFSANDWICH, record_has_specific_id_return_false)
{
    BeefSandwich *bf1 = new BeefSandwich(15, 0);
    ASSERT_FALSE(BeefSandwich::record_has_specific_id(1));
    delete bf1;
};

TEST(BEEFSANDWICH, test_get_size_of_record_container_should_return_size)
{
    BeefSandwich *bf1 = new BeefSandwich(15, 1);
    ASSERT_EQ(BeefSandwich::get_size_of_record_container(), 1);
    delete bf1;
};
