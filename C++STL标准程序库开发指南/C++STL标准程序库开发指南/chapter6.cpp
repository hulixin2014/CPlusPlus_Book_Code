#include "chapter6.h"
#include "stdafx.h"


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

template<typename T>
void myprint(valarray<T>& v)
{
    int size = v.size();
    for (int i = 0; i < size; ++i)
    {
        cout << v[i] << ", ";
    }
    cout << endl;
}

void example_6_8()
{
    valarray<double> v1(12), v2;
    for (int i = 0; i < 12; ++i)
    {
        v1[i] = 2 * (i + 1);
    }
    cout << "v1(Original):" << endl;
    myprint(v1);
    valarray<double> tv1 = valarray<double>(v1[slice(0, 4, 3)]);
    valarray<double> tv2 = valarray<double>(v1[slice(2, 4, 3)]);
    v1[slice(0, 4, 3)] = pow(tv1, tv2);
    cout << "v1(Calculated):" << endl;
    myprint(v1);
    valarray<double> v3(v1[slice(0, 4, 3)]);
    cout << "v3:" << endl;
    myprint(v3);
}

void example_6_9()
{
    valarray<double> v1(12), v2;
    for (int i = 0; i < 12; ++i)
    {
        v1[i] = 2 * (i + 1);
    }
    cout << "v1(Original):" << endl;
    myprint(v1);
    slice myslice(0, 4, 3);
    v2 = v1[myslice];
    cout << "v2(v2[slice(0,4,3)]):" << endl;
    myprint(v2);
}

void example_6_10()
{
    valarray<size_t> v1(20), v2, v3, v11;
    for (size_t i = 0; i < 20; ++i)
    {
        v1[i] = i;
        cout << i << ",";
    }
    cout << endl;
    valarray<size_t> len(5, 1);
    valarray<size_t> str1(3, 1);
    gslice g1(1, len, str1);
    v11 = v1[g1];
    cout << "subcollection of one dimension:" << endl;
    int size = v11.size();
    for (size_t j = 0; j < size; ++j)
    {
        v1[j] = j;
        cout << j << ",";
    }
    cout << endl;
    // 以上是以为子集
    size_t lengthv[] = { 2, 4 };
    size_t stridev[] = { 5, 3 };
    valarray<size_t> length(lengthv, 2);
    valarray<size_t> stride(stridev, 2);
    gslice g(1, length, stride);
    v2 = v1[g];
    cout << "subcollection of two dimension:" << endl;
    size = v2.size();
    for (size_t j = 0; j < size; ++j)
    {
        v2[j] = j;
        cout << j << ",";
    }
    cout << endl;
    // 以上是二维子集
    size_t lengthv2[] = { 2, 2, 3 };
    size_t stridev2[] = { 3, 2, 3 };
    valarray<size_t> length2(lengthv2, 3);
    valarray<size_t> stride2(stridev2, 3);
    gslice g2(1, length2, stride2);
    v3 = v1[g2];
    cout << "subcollection of three dimension:" << endl;
    size = v3.size();
    for (size_t j = 0; j < size; ++j)
    {
        v3[j] = j;
        cout << j << ",";
    }
    cout << endl;
    // 以上是三维子集
}

void example_6_11()
{
    double dim[12] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
    valarray<double> v1(dim, sizeof(dim) / sizeof(double));
    valarray<double> v2, v3;
    myprint(v1);
    bool B[] = { 0,1,0,1,0,0,1,1,1 };
    valarray<bool> mask_array(B, 9);
    v2 = v1[mask_array];
    myprint(v2);
    v1[v1 > 8.0] = 33.0;
    myprint(v1);
    v1[v1 < 8.0] = valarray<double>(v1[v1 < 8.0]) + 50.5;
    myprint(v1);
    bool B2[12];
    for (int i = 0; i < 12; ++i)
    {
        B2[i] = (bool)fmod(v1[i], 2);
    }
    for (int i = 0; i < 12; ++i)
    {
        cout << B2[i] << ",";
    }
    cout << endl;
    valarray<bool> VB2(B2, 12);
    v1[!VB2] = 0;
    myprint(v1);
}

void example_6_12()
{
    double dim[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
    valarray<double> v1(dim, 12), v2, v3;
    myprint(v1);
    valarray<size_t> vi(4);
    vi[0] = 4;
    vi[1] = 6;
    vi[2] = 7;
    vi[3] = 1;
    v2 = v1[vi];
    cout << "valarray v2(indirect_array):" << endl;
    myprint(v2);
    v3 = pow(v1, v2);
    cout << "v3 = pow(v1, v2):" << endl;
    myprint(v3);
}

int myop(int orig, int ele)
{
    return ele * 2 + orig;
}

void example_6_13()
{
    vector<int> vt;
    int dim[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
    vt.assign(dim, dim + 12);
    for (int i = 0; i < vt.size(); ++i)
    {
        cout << vt[i] << ",";
    }
    cout << endl;
    int sum = accumulate(vt.begin(), vt.end(), 0);
    cout << sum << endl;
    sum = accumulate(vt.begin(), vt.end(), 0, myop);
    cout << sum << endl;
}

void print14(int elem)
{
    cout << elem << ",";
}

int op1(int initV, int elem2)
{
    return initV + elem2;
}

int op2(int elem1, int elem2)
{
    return elem1 * 2 + elem2 * 3;
}

void example_6_14()
{
    int dim[] = { 1,2,3,4 };
    int dim2[] = { 3,4,5,6 };
    list<int> l1, l2;
    copy(dim, dim + 4, back_inserter(l1));
    for_each(l1.begin(), l1.end(), print14);
    cout << endl;
    copy(dim2, dim2 + 4, back_inserter(l2));
    for_each(l2.begin(), l2.end(), print14);
    cout << endl;
    int prod = inner_product(l1.begin(), l1.end(), l2.begin(), 0);
    cout << prod << endl;
    prod = inner_product(l1.begin(), l1.end(), l2.begin(), 0, op1, op2);
    cout << prod << endl;
    int sum = 0;
    for (int i = 0; i < 4; ++i)
    {
        sum += (dim[i] * 2 + dim2[i] * 3);
    }
    cout << sum << endl;
}

int op15(int pre_elem, int elem)
{
    return pre_elem + elem * 2;
}

void example_6_15()
{
    vector<int> v1, v2, v3;
    int dim[] = { 1,2,3,4 };
    v1.assign(dim, dim + 4);
    cout << "vector v1:" << endl;
    for_each(v1.begin(), v1.end(), print14);
    cout << endl;
    partial_sum(v1.begin(), v1.end(), back_inserter(v2));
    cout << "vector v2:" << endl;
    for_each(v2.begin(), v2.end(), print14);
    cout << endl;
    partial_sum(v1.begin(), v1.end(), back_inserter(v3), op15);
    cout << "vector v3:" << endl;
    for_each(v3.begin(), v3.end(), print14);
    cout << endl;
}

int op16(int elem2, int elem1)
{
    return elem2 * 5 - elem1 * 3;
}

void example_6_16()
{
    vector<int> v1, v2, v3;
    int dim[] = { 1,2,3,4 };
    v1.assign(dim, dim + 4);
    cout << "vector v1:" << endl;
    for_each(v1.begin(), v1.end(), print14);
    cout << endl;
    adjacent_difference(v1.begin(), v1.end(), back_inserter(v2));
    cout << "vector v2:" << endl;
    for_each(v2.begin(), v2.end(), print14);
    cout << endl;
    adjacent_difference(v1.begin(), v1.end(), back_inserter(v3), op16);
    cout << "vector v3:" << endl;
    for_each(v3.begin(), v3.end(), print14);
    cout << endl;
}
