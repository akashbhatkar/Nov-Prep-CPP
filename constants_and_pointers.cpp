#include<iostream>
using namespace std;
int main()
{
    int a = 10;
    int b = 20;

    const int* ptr = &a;// pointer to constant data
    ptr = &b;
    cout<<*ptr<<endl;
    // *ptr = 30; // Error

    int *const p = &a;// constant pointer
    cout<<*p<<endl;
    // p = &b; // Error
    *p = 40;
    cout<<*p<<endl;
    const int* const ptr1 = &a; // constant pointer to constant data
    cout<<*ptr1<<endl;
    // *ptr1 = 50; // Error
    // ptr1 = &b; //Error

}
