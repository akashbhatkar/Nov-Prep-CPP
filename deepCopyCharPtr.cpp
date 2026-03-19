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
