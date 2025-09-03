#include<iostream>
#include<gtest/gtest.h>
#include "../src/drink.h"
#include<string>

using namespace std;

TEST(DRINK , check_Drink_work_correctly_1){
    Drink drink;
    // Drink drink("dddd",0);

    // cout << drink.getSweetnessLevel() << endl;

    ASSERT_THROW(drink.getSweetnessLevel() ,std::string);
    ASSERT_THROW(drink.getName() ,std::string);
    ASSERT_THROW(Drink drink2("ss",0.1) ,std::string);
    ASSERT_THROW(Drink drink2("eeeee",-2) ,std::string);

}

TEST(DRINK , check_Drink_work_correctly_2){
    string str = "Signature Black Tea";
    Drink drink("Signature Black Tea",0.3);

    ASSERT_EQ(drink.getName() ,str);
    ASSERT_NEAR(drink.getSweetnessLevel() ,0.3,0.01);

}


TEST(DRINK , getName_work_correctly_1){
    string str = "Black";
    Drink drink("Black",0.3);
    string str2 = "White";
    Drink drink2("White",0.3);
    // cout << drink.getSweetnessLevel() << endl;

    ASSERT_EQ(drink.getName() ,str);
    ASSERT_EQ(drink2.getName() ,str2);

}

TEST(DRINK , getName_work_correctly_2){

    Drink drink;
    // cout << drink.getSweetnessLevel() << endl;
    drink.addTopping("Bubble");
    drink.addTopping("Sugar");

    ASSERT_THROW(drink.getName() ,std::string);
}

TEST(DRINK , getSweetnessLevel_work_correctly_1){

    Drink drink("Signature Black Tea",0.8);
    Drink drink2("Signature Black Tea2",0.3);
    // cout << drink.getSweetnessLevel() << endl;
    drink.addTopping("Bubble");
    drink.addTopping("Sugar");
    drink2.addTopping("Sugar2");

    ASSERT_NEAR(drink.getSweetnessLevel(),0.8,0.01);
    ASSERT_NEAR(drink2.getSweetnessLevel(),0.3,0.01);
}

TEST(DRINK , getSweetnessLevel_work_correctly_2){

    Drink drink;
    // cout << drink.getSweetnessLevel() << endl;
    drink.addTopping("Bubble");
    drink.addTopping("Sugar");

    ASSERT_THROW(drink.getSweetnessLevel(),std::string);
}

TEST(DRINK , addTopping_work_correctly_1){

    Drink drink("Signature Black Tea",0.9);
    // cout << drink.getSweetnessLevel() << endl;
    drink.addTopping("Bubble");
    drink.addTopping("Sugar");

    // ASSERT_THROW(drink.getSweetnessLevel(),std::string);
    ASSERT_EQ(drink.getToppingByIndex(0),"Bubble");
    ASSERT_NO_THROW(drink.addTopping("Water"));
    ASSERT_NO_THROW(drink.addTopping("Water2"));
    ASSERT_EQ(drink.getToppingCount(),4);
}

TEST(DRINK , addTopping_work_correctly_2){

    Drink drink("Signature Black Tea",0.9);
    // cout << drink.getSweetnessLevel() << endl;
    drink.addTopping("Bubble");
    drink.addTopping("Sugar");
    drink.addTopping("Water");

    drink.addTopping("Bubble3");
    drink.addTopping("Sugar2");
    drink.addTopping("Water1");
    // ASSERT_THROW(drink.getSweetnessLevel(),std::string);
    ASSERT_EQ(drink.getToppingByIndex(0),"Bubble");
    ASSERT_EQ(drink.getToppingCount(),6);
    ASSERT_NO_THROW(drink.addTopping("Water"));
}


TEST(DRINK , getToppingByIndex_work_correctly_1){

    Drink drink("Signature Black Tea",0.9);
    // cout << drink.getSweetnessLevel() << endl;
    drink.addTopping("Bubble");
    drink.addTopping("Sugar");
    drink.addTopping("Water");

    drink.addTopping("Bubble3");
    drink.addTopping("Sugar2");
    drink.addTopping("Water1");

    string tmp = "Bubble";
    string tmp2 = "Water";
    // ASSERT_THROW(drink.getSweetnessLevel(),std::string);
    ASSERT_EQ(drink.getToppingByIndex(0),tmp);
    ASSERT_EQ(drink.getToppingByIndex(2),tmp2);
}



TEST(DRINK , getToppingByIndex_work_correctly_2){

    Drink drink("Signature Black Tea",0.9);
    // cout << drink.getSweetnessLevel() << endl;
    drink.addTopping("Bubble");
    drink.addTopping("Sugar");
    drink.addTopping("Water");

    drink.addTopping("Bubble3");
    drink.addTopping("Sugar2");
    drink.addTopping("Water1");

    string tmp = "Bubble";
    // ASSERT_THROW(drink.getSweetnessLevel(),std::string);
    ASSERT_THROW(drink.getToppingByIndex(6),std::string);
    ASSERT_THROW(drink.getToppingByIndex(8),std::string);
}



TEST(DRINK , getToppingCount_work_correctly_1){

    Drink drink("Signature Black Tea",0.2);
    // cout << drink.getSweetnessLevel() << endl;
    drink.addTopping("Bubble");
    drink.addTopping("Sugar");
    drink.addTopping("Water");

    drink.addTopping("Bubble3");
    drink.addTopping("Sugar2");
    drink.addTopping("Water1");

    string tmp = "Bubble";
    // ASSERT_THROW(drink.getSweetnessLevel(),std::string);
    ASSERT_EQ(drink.getToppingCount(),6);
}



TEST(DRINK , getToppingCount_work_correctly_2){

    Drink drink("Signature Black Tea",0.2);
    // cout << drink.getSweetnessLevel() << endl;
    drink.addTopping("Bubble");
    drink.addTopping("Sugar");
    drink.addTopping("Water");

    drink.addTopping("Bubble3");
    // ASSERT_THROW(drink.getSweetnessLevel(),std::string);
    ASSERT_EQ(drink.getToppingCount(),4);
}