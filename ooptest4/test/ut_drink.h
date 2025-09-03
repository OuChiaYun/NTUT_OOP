
#include <iostream>
#include <gtest/gtest.h>
#include "../src/drink.h"
#include "../src/topping.h"
#include <string>

using namespace std;

TEST(SAMPLE, sample_TestWithCopyConstructor)
{
    Drink drink;
    drink = Drink("Signature Black Tea with Milk", 0.2, 40);

    ASSERT_EQ(drink.getName(), "Signature Black Tea with Milk");
    ASSERT_NEAR(drink.getSweetnessLevel(), 0.2, 0.01);
    ASSERT_NEAR(drink.getPrice(), 40, 0.01);
}

TEST(SAMPLE, sample_TestWithCopyAssignment)
{ //

    Drink drink("lululu", 0.3, 50);
    ASSERT_EQ(drink.getName(), "lululu");
    ASSERT_NEAR(drink.getSweetnessLevel(), 0.3, 0.01);
    ASSERT_NEAR(drink.getPrice(), 50, 0.01);
}

TEST(SAMPLE, sample_TestWithWrongValue)
{ //

    ASSERT_THROW(Drink("Bs", 0.3, 5), std::string);
    ASSERT_THROW(Drink("Bussss", -0.2, 5), std::string);
    ASSERT_THROW(Drink("Bussss", 0.4, -3), std::string);
}

TEST(SAMPLE, sample_TestWithtruetoppingindrink)
{ //

    Drink drink("yaya", 0.3, 50);
    drink.addTopping(Topping("qqqqq", 0.2, 3));

    ASSERT_EQ(drink.getToppingByIndex(0).getName(), "qqqqq");
    ASSERT_NEAR(drink.getToppingByIndex(0).getSweetnessLevel(), 0.2, 0.01);
    ASSERT_NEAR(drink.getToppingByIndex(0).getPrice(), 3, 0.01);

    ASSERT_EQ(drink.getToppingCount(), 1);
}

TEST(SAMPLE, sample_TestWithwrongtoppimgindrink)
{ //

    Drink drink;
    ASSERT_THROW(drink.addTopping(Topping()), std::string);
    ASSERT_THROW(drink.getToppingByIndex(0).getName(), std::string);
    ASSERT_THROW(drink.getToppingByIndex(0).getSweetnessLevel(), std::string);
    ASSERT_THROW(drink.getToppingByIndex(0).getPrice(), std::string);
}

TEST(SAMPLE, sample_TestWithaddtoppimginhavetoppingdrink)
{

    Drink drink("aaaa", 0.2, 3);
    Drink drink2("bbbb", 0.3, 4);
    drink2.addTopping(Topping("oooo", 0.2, 1));
    drink = drink2;
    for (int i = 0; i < 300; i++)
    {
        drink.addTopping(Topping("oooo", 0.2, 1));
    }

    ASSERT_EQ(drink.getToppingByIndex(0).getName(), "oooo");
}

TEST(SAMPLE, sample_TestWithwrongdrink)
{
    Drink drink3;
    ASSERT_THROW(drink3.getName(), std::string);
    ASSERT_THROW(drink3.getSweetnessLevel(), std::string);
    ASSERT_THROW(drink3.getPrice(), std::string);
}

TEST(SAMPLE, sample_TestWithwrongdrink2)
{

    Drink drink1("iiii", 0.05, 0.3);
    Drink drink2("jjjj", 0.1, 0.4);
    Drink drink3 = drink1 + drink2;

    cout << "  " << drink3.getName() << "   " << drink3.getSweetnessLevel() << " " << drink3.getPrice() << endl;
    Drink drink4 = drink3 + drink2 + drink1;
    cout << "  " << drink4.getName() << "   " << drink4.getSweetnessLevel() << " " << drink4.getPrice() << endl;
}
