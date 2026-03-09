#include<iostream>
using namespace std;

class Secret
{
  int n;
  public:
  Secret(int n_val) : n(n_val) {}
  
  friend class Truestee;
};
class Truestee
{
  public:
  int RevealSecret(const Secret &s_obj)
  {
    // cout<<"value of n = "<<s_obj.n<<endl;
    return s_obj.n;
  }
};

int main()
{
  Secret s(10);
  Truestee t;
  cout<<"n = "<<t.RevealSecret(s);
}

/* A friend class is a class that has been given permission to access the private and protected members of another class
* Friendship is Granted, Not Taken: Class A must explicitly say "Class B is my friend." Class B cannot simply declare itself a friend of Class A.
* Not Symmetric: If B is a friend of A, it doesn't mean A is a friend of B.
* Not Transitive: If A is a friend of B, and B is a friend of C, A is not automatically a friend of C.*/
