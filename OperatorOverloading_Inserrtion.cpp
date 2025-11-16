#include<iostream>
using namespace std;

class Complex
{
    public:
    int real, img;
    
    Complex(int r=0, int i = 0)
    {
        this->real = r;
        this->img = i;
    }
    friend ostream& operator<<(ostream& o_obj, const Complex &c_obj);
};

ostream& operator<<(ostream & o_obj, const Complex &c_obj)
{
    o_obj<<c_obj.real<<"+ i"<<c_obj.img<<endl;
    return o_obj;
}
int main()
{
    Complex C1(10, 20);
    cout<<C1;
    Complex C2(20, 30);
    cout<<C2;    
    cout<<C1<<C2;
}
