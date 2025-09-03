#include<iostream>
#include<string.h>
#include "../src/cake_showcase.h"

using namespace std;

TEST(CAKE_SHOWCASE,calc_total_price){
    ChocolateCake *cho1 = new ChocolateCake(45,15);
    ChocolateCake *cho2 = new ChocolateCake(45,15);
    ChocolateCake *cho3 = new ChocolateCake(45,15);
    ChocolateCake* c[] = {cho1,cho2,cho3};
    CakeShowcase<ChocolateCake> cs(3,c);

    ASSERT_EQ(cs.calc_total_price(),135);
    delete cho1;
    delete cho2;
    delete cho3;
};

TEST(CAKE_SHOWCASE,calc_total_sweet){
    ChocolateCake *cho1 = new ChocolateCake(45,15);
    ChocolateCake *cho2 = new ChocolateCake(45,15);
    ChocolateCake *cho3 = new ChocolateCake(45,15);
    ChocolateCake* c[] = {cho1,cho2,cho3};
    CakeShowcase<ChocolateCake> cs(3,c);

    ASSERT_EQ(cs.calc_total_sweet(),45);
    delete cho1;
    delete cho2;
    delete cho3;
};

TEST(CAKE_SHOWCASE,index){
    ChocolateCake *cho1 = new ChocolateCake(45,15);
    ChocolateCake *cho2 = new ChocolateCake(45,15);
    ChocolateCake *cho3 = new ChocolateCake(45,15);
    ChocolateCake* c[] = {cho1,cho2,cho3};
    CakeShowcase<ChocolateCake> cs(3,c);
    ASSERT_EQ(cs[2],cho3);
    delete cho1;
    delete cho2;
    delete cho3;
};

TEST(CAKE_SHOWCASE,index_ou_of_range){
    ChocolateCake *cho1 = new ChocolateCake(45,15);
    ChocolateCake *cho2 = new ChocolateCake(45,15);
    ChocolateCake *cho3 = new ChocolateCake(45,15);
    ChocolateCake* c[] = {cho1,cho2,cho3};
    CakeShowcase<ChocolateCake> cs(3,c);
    ASSERT_THROW(cs[5],std::out_of_range);
    delete cho1;
    delete cho2;
    delete cho3;
};

TEST(CAKE_SHOWCASE,to_string){
    ChocolateCake *cho1 = new ChocolateCake(45,15);
    ChocolateCake *cho2 = new ChocolateCake(45,15);
    ChocolateCake *cho3 = new ChocolateCake(45,15);
    ChocolateCake* c[] = {cho1,cho2,cho3};
    CakeShowcase<ChocolateCake> cs(3,c);
    string str = "| CakeName             | Price      | Sweet      |\n| -------------------- | ---------- | ---------- |\n| ChocolateCake        |         45 |         15 |\n| ChocolateCake        |         45 |         15 |\n| ChocolateCake        |         45 |         15 |\n| -------------------- | ---------- | ---------- |";
    ASSERT_EQ(cs.to_string(),str);
    delete cho1;
    delete cho2;
    delete cho3;
};

