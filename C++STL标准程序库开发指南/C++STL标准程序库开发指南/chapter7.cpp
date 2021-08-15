#include "chapter7.h"
#include "stdafx.h"

void example_7_1()
{
    char* cstring = "Hello";
    // 输出地址时需要使用void*
    cout << "string \"" << " " << cstring << "\"" << "is located at address: " << static_cast<void*>(cstring) << endl;
    cout << "string \"" << " " << cstring << "\"" << "is located at address: " << (void*)(cstring) << endl;
}

void example_7_2()
{
    double x = 12345678.123456789;
    cout.precision(6);
    cout << cout.scientific << x << endl;
}

void example_7_3()
{
    ios::iostate olde = cin.exceptions();
    cout << "old exceptions:" << olde << endl;
    int x = 0;
    try
    {
        cin.exceptions(ios::eofbit | ios::failbit | ios::badbit);
        cin >> x;
    }
    catch (exception& e)
    {
        cout << "exception:" << e.what() << endl;
    }
}

void example_7_4()
{
    char chdim[7] = { 0 };
    cin.get(chdim, 6, '\n');
    cout.write(chdim, 6);
    cout << endl;
    char ch;
    cin.get(ch);
    cout.put(ch);
    cout << endl;
    cin.getline(chdim, 6, '\n');
    cout.write(chdim, 6);
    cout << endl;
}

void example_7_5()
{
}

void example_7_6()
{
}

void example_7_7()
{
}

void example_7_8()
{
}
