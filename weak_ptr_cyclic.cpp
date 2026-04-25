#include<iostream>
#include<memory>
using namespace std;

class slave;
class master
{
  public:
  shared_ptr<slave> s_ptr;
  master(){cout<<"master constructor"<<endl;}
  ~master(){cout<<"master destructor"<<endl;}
};
class slave
{
  public:
  shared_ptr<master> m_ptr; // change this to weak ptr to resolve cyclic dependency
  slave(){cout<<"slave constructor"<<endl;}
  ~slave(){cout<<"slave destructor"<<endl;}
};

int main()
{
  shared_ptr<master> m = make_shared<master>();//(new master());
  shared_ptr<slave> s = make_shared<slave>();//(new slave());
  m->s_ptr = s;
  s->m_ptr = m;
  cout<<"master count = "<<m.use_count()<<endl;
  cout<<"slave count = "<<s.use_count()<<endl;
}
