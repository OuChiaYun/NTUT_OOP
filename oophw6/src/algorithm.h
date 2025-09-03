#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <iostream>
#include "order.h"
using namespace std;

// class Algorithm : public Order{

// bool comp(Alcohol *&a1, Alcohol *&a2)
// {
//     if (a1->get_alcohol_content() != a2->get_alcohol_content())
//     {
//         return a1->get_alcohol_content() < a2->get_alcohol_content();
//     }
//     return a1->get_name() < a2->get_name();
// }

void sort_alcohol_by_content(vector<Alcohol *> &alcohol)
{

    sort(alcohol.begin(), alcohol.end(), [](Alcohol *&a1, Alcohol *&a2)
         {
                if(a1->get_alcohol_content() != a2->get_alcohol_content()){
                    return a1->get_alcohol_content() < a2->get_alcohol_content();
                }
                return a1->get_name() < a2->get_name(); });

    // sort(alcohol.begin(), alcohol.end(), comp); // why if i use Lambda will lose some code coverage? 

    // cout << alcohol[0]->get_name() << " " << alcohol[0]->get_alcohol_content() << " " << alcohol[1]->get_alcohol_content() << endl;
};
void sort_alcohol_by_name(vector<Alcohol *> &alcohol)
{

    sort(alcohol.begin(), alcohol.end(), [](Alcohol *&a1, Alcohol *&a2)
         { return a1->get_name() < a2->get_name(); });
};
Alcohol *get_greatest_content_of_alcohol(vector<Alcohol *> alcohol)
{
    sort_alcohol_by_content(alcohol);
    return alcohol[alcohol.size() - 1];
};
Alcohol *get_smallest_content_of_alcohol(vector<Alcohol *> alcohol)
{
    sort_alcohol_by_content(alcohol);
    return alcohol[0];
};

    // }

#endif