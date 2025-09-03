#include "../src/alcohol.h"
#include "../src/tequila.h"


using namespace std;
//
TEST(TEQUILA,test_tequila_should_return_correct_name_price_content){

    Tequila tequila("item1",5,0.1);
    ASSERT_EQ(tequila.get_name(),"item1");
    ASSERT_EQ(tequila.get_price(),5);
    ASSERT_EQ(tequila.get_alcohol_content(),0.1);

}


TEST(TEQUILA,test_sour_is_default_should_throw_exception){
    Tequila tequila;
    ASSERT_THROW(tequila.get_name(),std::invalid_argument );
    ASSERT_THROW(tequila.get_price(),std::invalid_argument );
    ASSERT_THROW(tequila.get_alcohol_content(),std::invalid_argument );
}

// // //
TEST(TEQUILA,test_tequila_copy_constructor){
    Tequila tequila("item1",2,0.3);
    Tequila tequila2 = Tequila(tequila);

    ASSERT_EQ(tequila2.get_name(),"item1");
    ASSERT_EQ(tequila2.get_price(),2);
    ASSERT_EQ(tequila2.get_alcohol_content(),0.3);
    
}


TEST(TEQUILA,test_tequila_contains_name_length_is_empty_should_throw_exception){
    // ASSERT_THROW(Sour("",5,0.1),std::string);
    ASSERT_THROW(Tequila("",5,0.1),std::invalid_argument );
}

TEST(TEQUILA,test_tequila_contains_price_is_negative_should_throw_exception){
    ASSERT_THROW(Tequila("abcd",-1,0.1),std::invalid_argument );

}

TEST(TEQUILA,test_Tequila_contains_content_is_negative_should_throw_exception){
    ASSERT_THROW(Tequila("abcd",5,-0.1),std::invalid_argument );
}

TEST(TEQUILA,test_Tequila_delipute_alcohol_reduce_5_persent){
    // ASSERT_THROW(Sour("",5,0.1),std::string);
    Tequila tequila("item1",2,0.3);
    tequila.dilute();
    ASSERT_NEAR(tequila.get_alcohol_content(),0.285,0.01);

}

TEST(TEQUILA,test_Tequila_operatoradd_return_former_name_then_conbine_two_price_and_content){
    // ASSERT_THROW(Sour("",5,0.1),std::string);
    Tequila tequila1("item1",2,0.3);
    Tequila tequila2("item2",4,0.4);
    Tequila tequila3 = tequila1 + tequila2;
    ASSERT_EQ(tequila3.get_name(),"item1");
    ASSERT_EQ(tequila3.get_price(),6);
    ASSERT_NEAR(tequila3.get_alcohol_content(),0.35,01);
}

TEST(TEQUILA,test_sour_operator_declare_return_former_name_then_conbine_two_price_and_content){
    // ASSERT_THROW(Sour("",5,0.1),std::string);
    Tequila tequila1("item1",2,0.3);
    Tequila tequila2("item2",4,0.4);
    tequila2 = tequila1;

    ASSERT_TRUE(tequila1 == tequila2);

}

TEST(TEQUILA,test_tequila_operator_add_return_former_name_then_conbine_two_price_and_content){
    // ASSERT_THROW(Sour("",5,0.1),std::string);
    Tequila tequila1("item1",2,0.3);
    Tequila tequila2("item2",4,0.4);
    Tequila tequila3("item1",2,0.3);

    
    ASSERT_TRUE(tequila1 == tequila1);
    ASSERT_FALSE(tequila1 == tequila2);
    ASSERT_TRUE(tequila1 == tequila3);

}