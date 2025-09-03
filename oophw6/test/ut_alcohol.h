#include<iostream>

#include "../src/alcohol.h"
#include "../src/sour.h"
#include"../src/tequila.h"


using namespace std;
//
TEST(ALCOHOL,test_alcohol_should_return_correct_name_price_content){

    Alcohol& alcohol = *(new Sour("item1",5,0.1));
    ASSERT_EQ(alcohol.get_name(),"item1");
    ASSERT_EQ(alcohol.get_price(),5);
    ASSERT_EQ(alcohol.get_alcohol_content(),0.1);
    
    delete &alcohol;
}



TEST(ALCOHOL,test_alcohol_is_default_should_throw_exception){
    Alcohol& alcohol = *(new Sour());
    ASSERT_THROW(alcohol.get_name(),std::invalid_argument );
    ASSERT_THROW(alcohol.get_price(),std::invalid_argument );
    ASSERT_THROW(alcohol.get_alcohol_content(),std::invalid_argument );
    
    delete &alcohol;
}

//
// TEST(ALCOHOL,test_alcohol_copy_constructor_by_sour){
//     Alcohol& alcohol1 = *(new Sour("item1",2,0.3));
//     Alcohol& alcohol2 = *(new Sour(alcohol1));
//     // Sour sour1("abcd",3,0.2);
//     // Sour alcohol2(sour1);
//     ASSERT_EQ(alcohol2.get_name(),"item1");
//     ASSERT_EQ(alcohol2.get_price(),2);
//     ASSERT_EQ(alcohol2.get_alcohol_content(),0.3);
    
//     delete &alcohol1;
//     delete &alcohol2;
// }

// TEST(ALCOHOL,test_alcohol_copy_constructor_by_tequila){
//     Alcohol& alcohol1 = *(new Tequila("item1",2,0.3));
//     Alcohol& alcohol2 = *(new Tequila(alcohol1));
//     // Sour sour1("abcd",3,0.2);
//     // Sour alcohol2(sour1);
//     ASSERT_EQ(alcohol2.get_name(),"item1");
//     ASSERT_EQ(alcohol2.get_price(),2);
//     ASSERT_EQ(alcohol2.get_alcohol_content(),0.3);
    
//     delete &alcohol1;
//     delete &alcohol2;
// }


TEST(ALCOHOL,test_alcohol_contains_name_length_is_empty_should_throw_exception){
    // ASSERT_THROW(Sour("",5,0.1),std::string);
    ASSERT_THROW(*(new Sour("",5,0.1)),std::invalid_argument );
}

TEST(ALCOHOL,test_alcohol_contains_price_is_negative_should_throw_exception){
    ASSERT_THROW(*(new Sour("abcd",-1,0.1)),std::invalid_argument );

}

TEST(ALCOHOL,test_alcohol_contains_content_is_negative_should_throw_exception){
    ASSERT_THROW(*(new Sour("abcd",5,-0.1)),std::invalid_argument );
}