#include <iostream>
using namespace std;

class Complex
{
    public:
    int i, j;
    Complex(){}
    
    Complex(int i, int j)
    {
        this->i = i;
        this->j = j;
    }
    Complex operator + (Complex &obj)
    {
        Complex temp;
        temp.i = i + obj.i;
        temp.j = j+obj.j;
        return temp;
    }
    void Display()
    {
        cout<<i<<"+i"<<j<<endl;
    }
};
int main()
{
    Complex C1(10,20);
    Complex C2(20, 30);
    Complex C3 = C1+C2;
    C3.Display();
    Complex C4 = C2+C3;
    C4.Display();
}
