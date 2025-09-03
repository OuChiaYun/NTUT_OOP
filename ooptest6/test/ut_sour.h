#include<iostream>

#include "../src/alcohol.h"
#include "../src/sour.h"


using namespace std;
//
TEST(SOUR,test_sour_should_return_correct_name_price_content){

    Sour sour("item1",5,0.1);
    ASSERT_EQ(sour.get_name(),"item1");
    ASSERT_EQ(sour.get_price(),5);
    ASSERT_EQ(sour.get_alcohol_content(),0.1);

}


TEST(SOUR,test_sour_is_default_should_throw_exception){
    Sour sour;
    ASSERT_THROW(sour.get_name(),std::invalid_argument );
    ASSERT_THROW(sour.get_price(),std::invalid_argument );
    ASSERT_THROW(sour.get_alcohol_content(),std::invalid_argument );
}

//
TEST(SOUR,test_sour_copy_constructor){
    Sour sour("item1",2,0.3);
    Sour sour2 = Sour(sour);
    ASSERT_EQ(sour2.get_name(),"item1");
    ASSERT_EQ(sour2.get_price(),2);
    ASSERT_EQ(sour2.get_alcohol_content(),0.3);
    
}


TEST(SOUR,test_sour_contains_name_length_is_empty_should_throw_exception){
    // ASSERT_THROW(Sour("",5,0.1),std::string);
    ASSERT_THROW(Sour("",5,0.1),std::invalid_argument );
}

TEST(SOUR,test_sour_contains_price_is_negative_should_throw_exception){
    ASSERT_THROW(Sour("abcd",-1,0.1),std::invalid_argument );

}

TEST(SOUR,test_sour_contains_content_is_negative_should_throw_exception){
    ASSERT_THROW(Sour("abcd",5,-0.1),std::invalid_argument );
}

TEST(SOUR,test_sour_delipute_alcohol_reduce_30_persent){
    // ASSERT_THROW(Sour("",5,0.1),std::string);
    Alcohol &sour = *(new Sour("item1",2,0.3));
    sour.dilute();
    ASSERT_NEAR(sour.get_alcohol_content(),0.21,0.01);

    
    delete &sour;

}

TEST(SOUR,test_sour_operatoradd_return_former_name_then_conbine_two_price_and_content){
    // ASSERT_THROW(Sour("",5,0.1),std::string);
    Sour sour1("item1",2,0.3);
    Sour sour2("item2",4,0.4);
    Sour sour3 = sour1 + sour2;
    ASSERT_EQ(sour3.get_name(),"item1");
    ASSERT_EQ(sour3.get_price(),6);
    ASSERT_NEAR(sour3.get_alcohol_content(),0.35,01);
}

TEST(SOUR,test_sour_operator_declare_return_former_name_then_conbine_two_price_and_content){
    // ASSERT_THROW(Sour("",5,0.1),std::string);
    Sour sour1("item1",2,0.3);
    Sour sour2("item2",4,0.4);
    sour2 = sour1;

    ASSERT_TRUE(sour1 == sour2);

}

TEST(SOUR,test_sour_operator_add_return_former_name_then_conbine_two_price_and_content){
    // ASSERT_THROW(Sour("",5,0.1),std::string);
    Sour sour1("item1",2,0.3);
    Sour sour2("item2",4,0.4);
    Sour sour3("item1",2,0.3);

    
    ASSERT_TRUE(sour1 == sour1);
    ASSERT_FALSE(sour1 == sour2);
    ASSERT_TRUE(sour1 == sour3);

}