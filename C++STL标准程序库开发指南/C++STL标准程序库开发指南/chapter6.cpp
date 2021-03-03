#include "chapter6.h"
#include "stdafx.h"
#include <valarray>

void example_6_1()
{
    complex<double> c1(3.0, 4.0);
    complex<float> c2(polar(5.0, 1.0));
    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;
    cout << "c1:magnitude:" << abs(c1) << "(squared magnitude:)" << norm(c1) << "phase angle:" << arg(c1) << endl;
    cout << "c2:magnitude:" << abs(c2) << "(squared magnitude:)" << norm(c2) << "phase angle:" << arg(c2) << endl;
    cout << "c1 conjugated: " << conj(c1) << endl;
    cout << "c2 conjugated: " << conj(c2) << endl;
    cout << "c1*2=" << (c1 * 2.0) << endl;
    cout << "c1+c2=" << c1 + complex<double>(c2.real(), c2.imag()) << endl;
}

void example_6_2()
{
    complex<float> c1(1.5, 2.5);
    complex<float> c2(c1);
    complex<float> c3;
    float re = 3.5;
    float im = 5.2;
    cout << "c1:" << c1 << "    c2:" << c2 << endl;
    cout << "c3:" << c3 << endl;
    c3 = c1 + c2;
    cout << "c3=c1+c2 : " << c3 << endl;
    c3 = c1 - c2;
    cout << "c3=c1-c2 : " << c3 << endl;
    c3 = c1 * c2;
    cout << "c3=c1*c2 : " << c3 << endl;
    c3 = c1 / c2;
    cout << "c3=c1/c2 : " << c3 << endl;
    c1 += c2;
    cout << "c1+=c2 : " << c1 << endl;
    c1 -= c2;
    cout << "c1-=c2 : " << c1 << endl;
    c1 *= c2;
    cout << "c1*=c2 : " << c1 << endl;
    c1 /= c2;
    cout << "c1/=c2 : " << c1 << endl;
    bool cmp = c1 == c2;
    if (cmp)
    {
        cout << "c1==c2" << endl;
    }
    else
    {
        cout << "c1!=c2" << endl;
    }
}

void example_6_3()
{
    complex<float> c1(1.5, 2.5);
    complex<float> c2(5.0, 2.5);
    float a1 = abs(c1);
    float a2 = abs(c2);
    cout.precision(3);
    cout << "abs(c1): " << a1 << "   abs(c2): " << a2 << endl;
    a1 = norm(c1);
    a2 = norm(c2);
    cout.precision(3);
    cout << "norm(c1): " << a1 << "   norm(c2): " << a2 << endl;
    a1 = arg(c1);
    a2 = arg(c2);
    cout.precision(3);
    complex<float> c11;
    complex<float> c22;
    c11 = conj(c1);
    c22 = conj(c2);
    cout << "arg(c1): " << a1 << "   arg(c2): " << a2 << endl;
    cout << "conj(c1): " << c11 << endl;
    cout << "conj(c2): " << c22 << endl;
}

void example_6_4()
{
    complex<float> c1(1.5, 2.5);
    complex<float> c11;

    c11 = sin(c1);
    cout << "sin(c1):" << c11 << endl;

    c11 = cos(c1);
    cout << "cos(c1):" << c11 << endl;

    c11 = tan(c1);
    cout << "tan(c1):" << c11 << endl;

    c11 = sinh(c1);
    cout << "sinh(c1):" << c11 << endl;

    c11 = cosh(c1);
    cout << "cosh(c1):" << c11 << endl;

    c11 = tanh(c1);
    cout << "tanh(c1):" << c11 << endl;
}

void print(valarray<int>& array)
{
    int size = array.size();
    for (int i = 0; i < size; ++i)
    {
        cout << array[i] << ", ";
    }
    cout << endl;
}

void example_6_5()
{
    int dim[] = { 1,2,3,4,5,6,7,8,9 };
    valarray<int> val1(10);
    valarray<int> val2(0, 10);
    valarray<int> val3(dim, sizeof(dim) / sizeof(int));
    valarray<int> val4(val2);

    cout << "valarray val1:" << endl;
    print(val1);
    cout << "valarray val2:" << endl;
    print(val2);
    cout << "valarray val3:" << endl;
    print(val3);
    cout << "valarray val4:" << endl;
    print(val4);
}

int fn(int elem)
{
    int r = 0;
    r = elem * 2;
    return r;
}
void example_6_6()
{
    int dim[] = { 1, 2, -3, 4, 5, 6, -7, 8, 9 };
    valarray<int> val1(10);
    valarray<int> val2(-1, 10);
    valarray<int> val3(dim, sizeof(dim) / sizeof(int));
    valarray<int> val4(val2);
    valarray<int> val5;

    cout << "valarray val1:" << endl;
    print(val1);
    cout << "valarray val2:" << endl;
    print(val2);
    cout << "valarray val3:" << endl;
    print(val3);
    cout << "valarray val4:" << endl;
    print(val4);

    val5 = abs(val3);
    cout << "abs(val3)=" << endl;
    print(val5);

    int s = val3.size();
    int ma = val3.max();
    int mi = val3.min();

    cout << "The size of val3 is : " << s << endl;
    cout << "The maxinum value in val3 is :" << ma << endl;
    cout << "The mininum value in val3 is :" << mi << endl;

    //val3.resize(15);
    //cout << "val3 is resized, val3: " << endl;
    //print(val3);

    int he = val3.sum();
    cout << "The sum of val3 is : " << he << endl;

    val5 = val3.shift(5);
    cout << "val3 move 5 bits left." << endl;
    print(val5);
    val5 = val3.shift(-5);
    cout << "val3 move 5 bits right." << endl;
    print(val5);

    val5 = val3.cshift(8);
    cout << "val3 move 8 bits left circulatedly." << endl;
    print(val5);
    val5 = val3.cshift(-8);
    cout << "val3 move 8 bits right circulatedly." << endl;
    print(val5);

    val5 = val3.apply(&fn);
    cout << "val3 which has been delt by fn is below: " << endl;
    print(val5);
}

void print(valarray<double>& array)
{
    cout.precision(3);
    for (int i = 0; i < array.size(); ++i)
    {
        cout << array[i] << ", ";
    }
    cout << endl;
}

void example_6_7()
{
    double dim[] = { 1, 2, -3, 4, 5, 6, -7, 8, -9 };
    valarray<double> v1(dim, sizeof(dim) / sizeof(double));
    valarray<double> v2;
    valarray<double> v3(2, 9);
    cout << "v1: " << endl;
    print(v1);
    v2 = abs(v1);
    cout << "v2=abs(v1)= :" << endl;
    print(v2);
    v2 = pow(v1, v3);
    cout << "v2=pow(v1, v3)= :" << endl;
    print(v2);
    v2 = exp(v1);
    cout << "v2=exp(v1)= :" << endl;
    print(v2);
    v2 = sqrt(v1);
    cout << "v2=sqrt(v1)= :" << endl;
    print(v2);
    v2 = log(v1);
    cout << "v2=log(v1)= :" << endl;
    print(v2);
    v2 = log10(v1);
    cout << "v2=log10(v1)= :" << endl;
    print(v2);
    v2 = sin(v1);
    cout << "v2=sin(v1)= :" << endl;
    print(v2);
    v2 = cos(v1);
    cout << "v2=cos(v1)= :" << endl;
    print(v2);
    v2 = tan(v1);
    cout << "v2=tan(v1)= :" << endl;
    print(v2);
    v2 = sinh(v1);
    cout << "v2=sinh(v1)= :" << endl;
    print(v2);
    v2 = cosh(v1);
    cout << "v2=cosh(v1)= :" << endl;
    print(v2);
    v2 = tanh(v1);
    cout << "v2=tanh(v1)= :" << endl;
    print(v2);
    v2 = asin(v1);
    cout << "v2=asin(v1)= :" << endl;
    print(v2);
    v2 = acos(v1);
    cout << "v2=acos(v1)= :" << endl;
    print(v2);
    v2 = atan(v1);
    cout << "v2=atan(v1)= :" << endl;
    print(v2);
    v2 = atan2(v1, v3);
    cout << "v2=atan2(v1, v3)= :" << endl;
    print(v2);
}