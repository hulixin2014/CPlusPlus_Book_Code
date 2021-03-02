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

void example_5_2()
{
    list<int> l1;
    for (int i = 1; i <= 9; ++i)
    {
        l1.push_back(i);
    }
    cout << "vector : " << endl;
    for_each(l1.begin(), l1.end(), print);
    cout << endl;
    list<int>::iterator it;
    it = find(l1.begin(), l1.end(), 5);
    cout << "pos:" << *it << endl;
    list<int>::reverse_iterator itR(it);
    cout << "rpos:" << *itR << endl;
}

void example_5_3()
{
    int dim[] = { 1,2,3,4,5,6 };
    deque<int> d1;
    cout << "deque d1(1)：" << endl;
    copy(dim, dim + 6, back_inserter(d1));     // back_inserter是在#include<iterator>中定义
    copy(d1.begin(), d1.end(), ostream_iterator<int>(cout, ","));
    cout << endl;

    cout << "deque d1(2)：" << endl;
    front_inserter(d1) = 11;
    front_inserter(d1) = 22;   // 前端插入
    copy(d1.begin(), d1.end(), ostream_iterator<int>(cout, ","));
    cout << endl;

    cout << "deque d1(3)：" << endl;
    copy(d1.begin(), d1.end(), front_inserter(d1));
    copy(d1.begin(), d1.end(), ostream_iterator<int>(cout, ","));
    cout << endl;

    inserter(d1, d1.end()) = 33;
    inserter(d1, d1.end()) = 44;
    cout << "deque d1(4)：" << endl;
    copy(d1.begin(), d1.end(), ostream_iterator<int>(cout, ","));
    cout << endl;

    deque<int> d2;
    copy(d1.begin(), d1.end(), inserter(d2, d2.begin()));
    cout << "deque d2(5)：" << endl;
    copy(d2.begin(), d2.end(), ostream_iterator<int>(cout, ","));
    cout << endl;
}

void example_5_4()
{
    int dim[] = { 1,2,3,4,5,6,7,8,9 };
    vector<int> v1;
    ostream_iterator<int> itor(cout, "\n");
    v1.assign(dim, dim + 9);
    copy(v1.begin(), v1.end(), itor);
    cout << endl;
    string delim(",");
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, delim.c_str()));
    cout << endl;
    *itor = 22;     
    itor++;      // 这行代码可有可无
    *itor = 33;
    itor++;      // 这行代码可有可无
    *itor = 44;
}

void example_5_5()
{
    vector<int> v1;
    istream_iterator<int> inputCin(cin);
    istream_iterator<int> IEof;
    while (inputCin != IEof)
    {
        *inputCin;
        v1.push_back(*inputCin);
        ++inputCin;
    }
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, ","));
    cout << endl;
}

void example_5_6()
{
    int dim[] = { 1,2,3,4,5,6,7,8,9 };
    vector<int> v1;
    vector<int>::iterator it;
    v1.assign(dim, dim + 9);
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, ","));
    cout << endl;
    it = v1.begin();
    advance(it, 5);
    cout << "The sixth element: " << *it << endl;
    advance(it, -3);
    cout << "The third element: " << *it << endl;
}

void example_5_7()
{
    int dim[] = { 1,2,3,4,5,6,7,8,9 };
    list<int> l1;
    copy(dim, dim + 9, back_inserter(l1));
    copy(l1.begin(), l1.end(), ostream_iterator<int>(cout, ","));
    cout << endl;
    list<int>::iterator pos;
    pos = find(l1.begin(), l1.end(), 5);
    if (pos != l1.end())
    {
        cout << "The distance between beginning and 5:" << distance(l1.begin(), pos) << endl;
    }
    else
    {
        cout << "5 not found." << endl;
    }
}

void example_5_8()
{
    int dim[] = { 1,2,3,4,5,6,7,8,9 };
    double Vdim[] = { 1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9 };
    vector<int> v1;
    list<double> l1;
    v1.assign(dim, dim + 9);
    copy(Vdim, Vdim + 9, back_inserter(l1));

    cout << "vector v1:" << endl;
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, ","));
    cout << endl;
    cout << "list l1:" << endl;
    copy(l1.begin(), l1.end(), ostream_iterator<double>(cout, ","));
    cout << endl;

    vector<int>::iterator itV;
    itV = v1.end();
    itV--;
    iter_swap(v1.begin(), itV);
    cout << "vector v1 (swap first.): " << endl;
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, ","));
    cout << endl;

    list<double>::iterator itLs, itLe;
    itLs = l1.begin();
    advance(itLs, 2);
    itLe = l1.end();
    advance(itLe, -3);
    iter_swap(itLs, itLe);
    cout << "list l1 (swap first.): " << endl;
    copy(l1.begin(), l1.end(), ostream_iterator<double>(cout, ","));
    cout << endl;

    itV = v1.begin();
    //iter_swap(itLs, itV);    这里再vs2015编译不通过
    cout << "vector v1 (swap second.): " << endl;
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, ","));
    cout << endl;
    cout << "list l1 (swap second.): " << endl;
    copy(l1.begin(), l1.end(), ostream_iterator<double>(cout, ","));
    cout << endl;
}

