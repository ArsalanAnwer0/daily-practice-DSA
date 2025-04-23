#include <iostream>
using namespace std;

int main()
{
    // int num = 5;
    // cout << num << endl;

    // // address of operator - &

    // cout << "address of num is " << &num << endl;

    // int *ptr = &num;

    // cout << "Address is : " << ptr << endl;
    // cout << "Value is "  << *ptr << endl;

    // double d = 4.4;
    // double* p2 = &d;

    // cout << "Address of d is " << p2 << endl;
    // cout << "Vakue is: " << *p2 << endl;

    // cout << "Size of integerr is " << sizeof(num) << endl;
    // cout << "Size of pointer is " << sizeof(ptr) << endl;
    // cout << "Size of pointer is " << sizeof(p2) << endl;

    // pointer of int is created, and pointed to some 
    // garbage value
    // int *p = nullptr;
    // cout << *p << endl;

    // int i = 5;
    // int *q = &i;
    // int *p = 0;

    // p=&i;

    // cout << *p << endl;
    // cout << *q << endl;

    // int num = 5;
    // int  a = num;
    // a++;
    // cout << num << endl;

    // int *p = &num;
    // ++(*p);
    // cout << num << endl;

    // int num = 5;
    // int*p = &num;
    // int *q = p;
    // int**r = &q;
    // int***f = &r;
    // cout << q << endl;
    // cout << p << endl;

    int i = 5;
    int*t =&i;
    cout << (*t)++ << endl;
    cout << *t << endl;






}