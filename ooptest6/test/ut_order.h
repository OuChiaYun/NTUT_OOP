#include"../src/order.h"
// #include<gtest/test>
#include"../src/sour.h"
#include"../src/tequila.h"


using namespace std;

TEST(ORDER,test_order_append_alcohol_return_count_and_total_price){
    Order order;
    Alcohol* alcohol1 = (new Sour("item1",2,0.3));
    Alcohol* alcohol2 = (new Tequila("item2",4,0.7));
    order.append_alcohol(alcohol1);
    order.append_alcohol(alcohol2);
    ASSERT_EQ(order.get_alcohol_count(),2);
    ASSERT_EQ(order.get_total_price(),6);
    // sort_alcohol_by_content(order._alcohol_list);
    delete alcohol1;
    delete alcohol2;

}
