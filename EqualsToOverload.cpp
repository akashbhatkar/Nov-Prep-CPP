#include<iostream>
using namespace std;

class Equals
{
  int x;
  public:
  Equals(int x_val) : x(x_val) {}
  
  friend bool operator ==(const Equals &lhs, const Equals &rhs)
  {
    return lhs.x == rhs.x;
  }
};
int main()
{
  Equals E1(10);
  Equals E2(10);

  if(E1 == E2)
  cout<<"Equal"<<endl;
  else
  cout<<"Not Equal"<<endl;
  
  if(10 == E2)
  cout<<"Equal"<<endl;
  else
  cout<<"Not Equal"<<endl;
  
  if(E1 == 20)
  cout<<"Equal"<<endl;
  else
  cout<<"Not Equal"<<endl;
}

/*  In C++, an operator can be overloaded either as a member function or a non-member (friend) function.
Symmetry: If you define == as a member function, the left-hand side must be an object of the class (e.g., E1 == 10). However, 10 == E1 would fail because an integer doesn't have a .operator==() method that accepts an Equals object.
The Friend Advantage: By using a friend function, the operator exists "outside" the class. This allows C++ to perform Implicit Conversion on both the left and right sides.
2. Why take two arguments?
Since a friend function is not a member of the class, it doesn't have a this pointer.
A member version only needs one argument: bool operator==(const Equals& rhs). It compares this->x with rhs.x.
A friend version needs both sides of the == symbol to be passed in explicitly as lhs (Left Hand Side) and rhs (Right Hand Side).


E1 == E2: Directly compares two objects. Result: Equal.
10 == E2: Converts 10 to a temporary Equals object, then compares. Result: Equal.
E1 == 20: Converts 20 to a temporary Equals object, then compares. Result: Not Equal.  */
