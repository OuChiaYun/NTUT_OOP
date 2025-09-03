#include <iostream>
#include "../src/drink.h"

using namespace std;

TEST(DRINK, tryit)
{
    string str = "hello";
    Drink drink("hello", 0.5);
    string strTop = "1111";
    drink.addTopping("1111");

    ASSERT_EQ(drink.getName(), str);
    ASSERT_NEAR(drink.getSweetnessLevel(), 0.5, 0.01);
    ASSERT_EQ(drink.getToppingByIndex(0), strTop);
    ASSERT_THROW(drink.getToppingByIndex(1), std::string);
    ASSERT_THROW(drink.getToppingByIndex(-1), std::string);
    ASSERT_EQ(drink.getToppingCount(),1);
}

TEST(DRINK, tryit2)
{
    Drink drink;

    ASSERT_THROW(drink.getName(), std ::string);
    ASSERT_THROW(drink.getSweetnessLevel(), std::string);

    ASSERT_THROW(Drink("1", 0.1),std::string);
    ASSERT_THROW(Drink("2222", -0.1), std::string);
}
