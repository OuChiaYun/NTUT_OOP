#include"../src/order.h"
#include"../src/sour.h"
#include"../src/tequila.h"
#include"../src/algorithm.h"


using namespace std;

TEST(ALGORITHM,test_alcohol_list_sort_if_content_same_by_content){
    Order order;
    Alcohol* alcohol1 = (new Sour("item1",2,0.7));
    Alcohol* alcohol2 = (new Tequila("item2",4,0.3));
    order.append_alcohol(alcohol1);
    order.append_alcohol(alcohol2);
    sort_alcohol_by_content(order._alcohol_list);
    // cout << order._alcohol_list[0]->get_name() << " " << order._alcohol_list[0]->get_alcohol_content() << " " << order._alcohol_list[1]->get_alcohol_content() << endl;

    ASSERT_EQ(order._alcohol_list[0]->get_alcohol_content(),0.3);
    ASSERT_EQ(order._alcohol_list[0]->get_name(),"item2");

    delete alcohol1;
    delete alcohol2;
}

TEST(ALGORITHM,test_alcohol_list_sort_if_content_same_by_content_else_by_name){
    Order order;
    Alcohol* alcohol1 = (new Sour("item1",2,0.3));
    Alcohol* alcohol2 = (new Tequila("item2",4,0.3));
    order.append_alcohol(alcohol1);
    order.append_alcohol(alcohol2);
    sort_alcohol_by_content(order._alcohol_list);
    // cout << order._alcohol_list[0]->get_name() << " " << order._alcohol_list[0]->get_alcohol_content() << " " << order._alcohol_list[1]->get_alcohol_content() << endl;

    ASSERT_EQ(order._alcohol_list[0]->get_alcohol_content(),0.3);
    ASSERT_EQ(order._alcohol_list[0]->get_name(),"item1");

    delete alcohol1;
    delete alcohol2;

}



TEST(ALGORITHM,test_alcohol_list_sort_by_name){
    Order order;
    Alcohol* alcohol1 = (new Sour("item3",2,0.7));
    Alcohol* alcohol2 = (new Tequila("item2",4,0.3));
    order.append_alcohol(alcohol1);
    order.append_alcohol(alcohol2);
    sort_alcohol_by_name(order._alcohol_list);
    // cout << order._alcohol_list[0]->get_name() << " " << order._alcohol_list[0]->get_alcohol_content() << " " << order._alcohol_list[1]->get_name() << endl;
    ASSERT_EQ(order._alcohol_list[0]->get_name(),"item2");
    delete alcohol1;
    delete alcohol2;

}

TEST(ALGORITHM,test_alcohol_list_get_by_max_content){
    Order order;
    Alcohol* alcohol1 = (new Sour("item1",2,0.7));
    Alcohol* alcohol2 = (new Tequila("item2",4,0.3));
    order.append_alcohol(alcohol1);
    order.append_alcohol(alcohol2);
    Alcohol* alcohol_largest = get_greatest_content_of_alcohol(order._alcohol_list);
    //cout << alcohol_largest->get_name() << " " << alcohol_largest->get_alcohol_content();
    // cout << order._alcohol_list[0]->get_name() << " " << order._alcohol_list[0]->get_alcohol_content() << " " << order._alcohol_list[1]->get_name() << endl;
    ASSERT_EQ(alcohol_largest->get_name(),"item1");
    ASSERT_EQ(alcohol_largest->get_alcohol_content(),0.7);
    delete alcohol1;
    delete alcohol2;
    // delete alcohol_largest;
}

TEST(ALGORITHM,test_alcohol_list_get_min_content){
    Order order;
    Alcohol* alcohol1 = (new Sour("item1",2,0.7));
    Alcohol* alcohol2 = (new Tequila("item2",4,0.3));
    order.append_alcohol(alcohol1);
    order.append_alcohol(alcohol2);
    Alcohol* alcohol_min= get_smallest_content_of_alcohol(order._alcohol_list);
    // cout << alcohol_largest->get_name() << " " << alcohol_largest->get_alcohol_content();
    // cout << order._alcohol_list[0]->get_name() << " " << order._alcohol_list[0]->get_alcohol_content() << " " << order._alcohol_list[1]->get_name() << endl;
    ASSERT_EQ(alcohol_min->get_name(),"item2");
    ASSERT_EQ(alcohol_min->get_alcohol_content(),0.3);
    delete alcohol1;
    delete alcohol2;
    // delete alcohol_min;
}


