#include "chapter5.h"
#include "stdafx.h"

void print(int elem)
{
    cout << elem << ",";
}

void example_5_1()
{
    list<int> l1;
    for (int i = 0; i <= 9; ++i)
    {
        l1.push_back(i);
    }
    for_each(l1.begin(), l1.end(), print);
    cout << endl;
    for_each(l1.rbegin(), l1.rend(), print);
    cout << endl;
}