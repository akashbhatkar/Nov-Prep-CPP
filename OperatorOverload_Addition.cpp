#include <iostream>
using namespace std;

class Complex
{
    public:
    // Replaced 'i' with 'real' and 'j' with 'img'
    int real, img; 
    Complex(){}
    
    Complex(int i, int j)
    {
        // Assigned parameter 'i' to 'real' and 'j' to 'img'
        this->real = i; 
        this->img = j; 
    }
    Complex operator + (Complex &obj)
    {
        Complex temp;
        // Used 'real' and 'img' for addition
        temp.real = real + obj.real; 
        temp.img = img+obj.img;
        return temp;
    }
    void Display()
    {
        // Used 'real' and 'img' for display
        cout << real << "+i" << img << endl; 
    }
};
int main()
{
    Complex C1(10,20);
    Complex C2(20, 30);
    // C3 = (10 + i20) + (20 + i30) = 30 + i50
    Complex C3 = C1+C2;
    C3.Display();
    // C4 = (20 + i30) + (30 + i50) = 50 + i80
    Complex C4 = C2+C3;
    C4.Display();
    return 0;
}
