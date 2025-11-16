#include <iostream>
using namespace std;
class Complex
{
  public:
  int real, img;
  Complex(int real = 0, int img = 0)
  {
      this->real = real;
      this->img = img;
  }
  
  friend istream& operator>>(istream& i_obj, Complex& c_obj);
};

istream& operator>> (istream& i_obj, Complex& c_obj)
{
    cout<<"Enter real part"<<endl;
    i_obj>>c_obj.real;
    cout<<"Enter imaginary part"<<endl;
    i_obj>>c_obj.img;
    return i_obj;
}
int main()
{
    Complex C;
    cin>>C;
    cout<<"Entered Complex number is = "<<C.real<<" + i"<<C.img<<endl;
}
