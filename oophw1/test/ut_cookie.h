#include<iostream>
#include"../src/cookie.h"



TEST(MAX_DV,N_IS_EVEN)
{
    int array[] = {1,2,3,4}; 
    int n = 4;
    int output = max_dv(n,array); 
    ASSERT_EQ(output,6); 

};

TEST(MAX_DV,N_IS_EVEN2)
{
    int array[] = {1,2,3,4,1,1};
    int n = 6;
    int output = max_dv(n,array);
    ASSERT_EQ(output,7); 

};

TEST(MAX_DV,N_IS_ODD)
{
    int array[] = {1,2,3,4,5}; 
    int n = 5;
    int output = max_dv(n,array);
    ASSERT_EQ(output,9);

};

TEST(MAX_DV,N_IS_ODD2)
{
    int array[] = {1,2,3,4,5,1,10}; 
    int n = 7;
    int output = max_dv(n,array);
    ASSERT_EQ(output,19);

};

TEST(MAX_DV,DV_IS_NEGATIVE)
{

    int array[] = {1, -3, 3, 4}; 
    int n = 4;
    int output = max_dv(n,array);
    ASSERT_EQ(output,-1); 
};

TEST(MAX_DV,DV_IS_NEGATIVE2)
{

    int array[] = {0,0,0,0,-1}; 
    int n = 5;
    int output = max_dv(n,array);
    ASSERT_EQ(output,-1); 
};

TEST(MAX_DV,N_IS_NEGATIVE)
{

    int array[] = {1, -3, 3, 4}; 
    int n = -4;
    int output = max_dv(n,array);
    ASSERT_EQ(output,-1); 
};

TEST(MAX_DV,N_IS_NEGATIVE2)
{

    int array[] = {1, -3, 3, 4,5};
    int n = -5;
    int output = max_dv(n,array);
    ASSERT_EQ(output,-1); 
};

