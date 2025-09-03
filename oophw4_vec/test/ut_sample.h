
#include <iostream>
#include <gtest/gtest.h>
#include "../src/drink.h"
#include <string>

using namespace std;

TEST(SAMPLE, DRINK_WORK_CORRECTLY_1)
{ //     /* Setup name to "Signature Black Tea with Milk"（熟成歐蕾）. */
    /* Setup sweetness level to 0.3 */
    /* Setup price to 45 */
    string nam = "Signature Black Tea with Milk";
    double swt = 0.2;
    double pri = 40;

    Drink drink("Signature Black Tea with Milk", 0.2, 40);

    ASSERT_EQ(drink.getName(), nam);
    ASSERT_NEAR(drink.getSweetnessLevel(), swt, 0.01);
    ASSERT_NEAR(drink.getPrice(), pri, 0.01);
}

TEST(SAMPLE, DRINK_WORK_CORRECTLY_2)
{ //

    Drink drink;
    ASSERT_THROW(drink.getPrice(), std::string);
    ASSERT_THROW(Drink drink2("o", 0.5, 1), std::string);
    ASSERT_THROW(Drink drink2("ooooo", 2, 1), std::string);
    ASSERT_THROW(Drink drink2("ooooo", 0.2, -1), std::string);
    ASSERT_THROW(Drink drink2("ooooo", -1, -1), std::string);
}

TEST(SAMPLE, DRINK_getName_WORK_CORRECTLY_1)
{ //
    string nam = "Signature Black Tea with Milk";
    double swt = 0.2;
    double pri = 40;
    Drink drink("Signature Black Tea with Milk", 0.2, 40);

    ASSERT_EQ(drink.getName(), nam);
}

TEST(SAMPLE, DRINK_getName_WORK_CORRECTLY_2)
{ //
    Drink drink2;
    ASSERT_THROW(drink2.getName(), std::string);
}

TEST(SAMPLE, DRINK_getSweetnessLevel_WORK_CORRECTLY_1)
{ //
    string nam = "Signature Black Tea with Milk";
    double swt = 0.2;
    double pri = 30;
    Drink drink("Signature Black Tea with Milk", 0.2, 30);

    ASSERT_NEAR(drink.getSweetnessLevel(), swt, 0.01);
}

TEST(SAMPLE, DRINK_getSweetnessLevel_WORK_CORRECTLY_2)
{ //
    Drink drink2;
    ASSERT_THROW(drink2.getSweetnessLevel(), std::string);
}

TEST(SAMPLE, DRINK_getPrice_WORK_CORRECTLY_1)
{ //
    string nam = "Signature Black Tea with Milk";
    double swt = 0.1;
    double pri = 30;
    Drink drink("Signature Black Tea with Milk", 0.1, 30);

    ASSERT_NEAR(drink.getPrice(), pri, 0.01);
}

TEST(SAMPLE, DRINK_getPrice_WORK_CORRECTLY_2)
{ //
    Drink drink2;
    ASSERT_THROW(drink2.getPrice(), std::string);
}

TEST(SAMPLE, DRINK_addTopping_WORK_CORRECTLY_1)
{ //
    string nam = "Signature Black Tea with Milk";
    double swt = 0.4;
    double pri = 31;

    Drink drink("Signature Black Tea with Milk", 0.1, 30);
    // drink.addTopping(Topping("kkkkk",0.3,1));
    ASSERT_NO_THROW(drink.addTopping(Topping("kkkkk", 0.3, 1)));
    ASSERT_NEAR(drink.getSweetnessLevel(), swt, 0.01);
    ASSERT_NEAR(drink.getPrice(), pri, 0.01);
}

TEST(SAMPLE, DRINK_addTopping_WORK_CORRECTLY_2)
{ //
    // Drink drink2;
    Drink drink;
    ASSERT_NO_THROW(drink.addTopping(Topping("kkkkk", 0.3, 1)));
    // ASSERT_NO_THROW(drink.addTopping(Topping("kkkkk",0.3,1)), std::string);
    // ASSERT_NO_THROW(drink.addTopping(Topping("kkkkk",0.3,1)), std::string);
    ASSERT_THROW(drink.getName(), std::string);
    ASSERT_THROW(drink.getSweetnessLevel(), std::string);
    ASSERT_THROW(drink.getPrice(), std::string);
}

TEST(SAMPLE, DRINK_getToppingByIndex_WORK_CORRECTLY_1)
{ //
  // Drink drink2;

    string nam = "Signature Black Tea with Milk";
    double swt = 0.1;
    double pri = 31;

    Drink drink("Signature Black Tea with Milk", 0.1, 30);

    Topping topping_0 = Topping("kkkkk", 0.3, 1);
    ASSERT_NO_THROW(drink.addTopping(topping_0));

    drink.addTopping(Topping("aaaaa", 0.3, 2));
    drink.addTopping(Topping("bbbbb", 0.2, 3));
    drink.addTopping(Topping("ccccc", 0.1, 4));

    Topping topping_4 = Topping("ddddd", 0.2, 5);
    drink.addTopping(topping_4);

    string str1 = "kkkkk";
    string str2 = "ddddd";

    Topping t1 = drink.getToppingByIndex(0);
    Topping t2 = drink.getToppingByIndex(4);

    ASSERT_EQ(drink.getToppingByIndex(0).getName(), "kkkkk");
    ASSERT_EQ(drink.getToppingByIndex(0).getSweetnessLevel(), 0.3);
    ASSERT_EQ(drink.getToppingByIndex(0).getPrice(), 1);

    ASSERT_EQ(drink.getToppingByIndex(4).getName(), "ddddd");
    ASSERT_EQ(drink.getToppingByIndex(4).getSweetnessLevel(), 0.2);
    ASSERT_EQ(drink.getToppingByIndex(4).getPrice(), 5);
    ASSERT_THROW(drink.getToppingByIndex(-1), std::string);
    ASSERT_THROW(drink.getToppingByIndex(5), std::string);
}

TEST(SAMPLE, DRINK_getToppingCount_WORK_CORRECTLY_1)
{ //
  // Drink drink2;
    Drink drink("Signature Black Tea with Milk", 0.1, 30);

    Topping topping_0 = Topping("kkkkk", 0.3, 1);
    ASSERT_NO_THROW(drink.addTopping(topping_0));

    drink.addTopping(Topping("aaaaa", 0.3, 2));
    drink.addTopping(Topping("bbbbb", 0.2, 3));
    drink.addTopping(Topping("ccccc", 0.1, 4));

    ASSERT_EQ(drink.getToppingCount(), 4);
}

TEST(SAMPLE, DRINK_operator_WORK_CORRECTLY_1)
{ //
  // Drink drink2;
    string str = "Signature Black Tea with Milk";
    double swt = 0.9;
    double pri = 36;
    Drink drink("Signature Black Tea with Milk", 0.1, 30);

    string str_0 = "kkkkk";
    Topping topping_0 = Topping("kkkkk", 0.3, 1);
    ASSERT_NO_THROW(drink.addTopping(topping_0));

    drink.addTopping(Topping("aaaaa", 0.3, 2));
    drink.addTopping(Topping("bbbbb", 0.2, 3));

    Drink drink3;
    ASSERT_NO_THROW(drink3 = drink);
    Drink drink2;
    drink2 = drink3;
    ASSERT_EQ(drink2.getName(), str);
    ASSERT_NEAR(drink2.getSweetnessLevel(), swt, 0.01);
    ASSERT_NEAR(drink2.getPrice(), pri, 0.01);

    ASSERT_EQ(drink2.getToppingByIndex(0).getName(), str_0);
    ASSERT_NEAR(drink2.getToppingByIndex(0).getSweetnessLevel(), 0.3, 0.01);
    ASSERT_NEAR(drink2.getToppingByIndex(0).getPrice(), 1, 0.01);

    // ASSERT_EQ(drink2.getToppingCount(), 3);
}