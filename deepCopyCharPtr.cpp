#include<iostream>
#include<cstring>
using namespace std;

class mystring
{
  char* data;
  public:
  mystring(char *ptr = "")
  {
    cout<<"constructor called"<<endl;
    data = new char[strlen(ptr)+1];
    strcpy(data, ptr);
  }
  mystring(const mystring& m_obj)
  {
    cout<<"copy constructor called"<<endl;
    data = new char[strlen(m_obj.data)+1];
    strcpy(data, m_obj.data);
  }
  mystring& operator = (const mystring& m_obj)
  {
    cout<<"copy assignment called"<<endl;
    if(this!= &m_obj)
    {
      delete[] data;
      data = new char[strlen(m_obj.data)+1];
      strcpy(data, m_obj.data);
    }
    return *this;
  }
  mystring(mystring&& m_obj)
  {
    cout<<"move constructor called"<<endl;
    data = m_obj.data;
    m_obj.data = nullptr;
  }
  mystring& operator = (mystring&& m_obj)
  {
    cout<<"move assignment called"<<endl;
    if(this!= &m_obj)
    {
      delete[] data;
      data = m_obj.data;
      m_obj.data = nullptr;
    }
    return *this;
  }
  void Display()
  {
    cout<<"=================================="<<endl;
    cout<<"data = "<<data<<endl
    <<"Address stored at data = "<<(void*)data<<endl;
  }
  ~mystring()
  {
    cout<<"destructor called"<<endl;
      delete[] data;
      data = nullptr;
  }
};
int main()
{
  mystring m1("hello");
  m1.Display();
  
  mystring m2(m1);
  m2.Display();
  
  mystring m3;
  m3 = m1;
  m3.Display();
  
  mystring m4(move(m2));
  m4.Display();
  
  mystring m5;
  m5 = move(m4);
  m5.Display();
}
/* output
Constructor called
==================================
data = hello
Address stored at data = 0x5586bedacd30
copy constructor called
==================================
data = hello
Address stored at data = 0x5586bedacd50
constructor called
copy assignment called
==================================
data = hello
Address stored at data = 0x5586bedacd70
move constructor called
==================================
data = hello
Address stored at data = 0x5586bedacd50
constructor called
move assignment called
==================================
data = hello
Address stored at data = 0x5586bedacd50
destructor called
destructor called
destructor called
destructor called
destructor called*/

/* Why to use && in the move sematics
Rvalue references allow a function to distinguish temporary objects (rvalues) from objects with a name (lvalues).
When a temporary object or std::move(obj) is passed, it becomes an rvalue, which can bind to Type&&.

  temporary object means a unnamed object which can goes out of scope after the calling instruction.
  ex. mystring m5(mystring("Akash");
here mystring("Akash") will create one object and it says to move it into m5 but it is a temporary object to support this we need 
&& to add into the move constructor or assignment operator
* Temporaries (rvalues) are unnamed objects that last only until the end of the full expression.
* Move constructor with Type&& binds to these temporaries, enabling resource transfer.
* After moving, the temporary is left in a valid but empty state, and the new object takes ownership.
* The && lets your move constructor/assignment accept rvalues (temporaries) directly.
* But named variables (lvalues) cannot bind to && directly.
* So, to treat a named object as an rvalue and enable moving, you use std::move to cast it to an rvalue reference.
* This allows calling the move constructor/assignment on normal objects explicitly.*/

/* Standard library containers (like std::vector, std::string) prefer to use move operations during their internal reallocations 
only if the move constructor or move assignment is noexcept
if not used noexcept then, move operations might throw, containers fall back to copying instead of moving to maintain strong exception safety, 
which can be more expensive.
Without noexcept, some STL containers might avoid using your move constructor and copy instead, hurting performance.
In move semantics, marking functions noexcept promises they won't throw exceptions,
which helps optimize performance and guarantees safety during moves. */

