#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

void sort_alcohol_by_content(vector<Alcohol *> &alcohol)
{
    sort(alcohol.begin(), alcohol.end(), [](Alcohol *a, Alcohol *b)
         {
        if (a->get_alcohol_content() != b->get_alcohol_content()){
            return a->get_alcohol_content() < b->get_alcohol_content();
        }
            return a->get_name() < b->get_name(); });
}

void sort_alcohol_by_name(vector<Alcohol *> &alcohol)
{
    cout << 'a';
    cout << alcohol[0]->get_name() << endl;
    sort(alcohol.begin(), alcohol.end(), [](Alcohol *a, Alcohol *b)
         {
            std::cout << a->get_name() <<std::endl;

            return a->get_name() < b->get_name(); });
}
Alcohol *get_greatest_content_of_alcohol(vector<Alcohol *> alcohol)
{
    sort_alcohol_by_content(alcohol);
    return alcohol[alcohol.size() - 1];
}

Alcohol *get_smallest_content_of_alcohol(vector<Alcohol *> alcohol)
{
    sort_alcohol_by_content(alcohol);
    return alcohol[0];
}

#endif