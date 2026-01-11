#include<iostream>
using namespace std;

template<typename T>
class unique
{
    private:
    T* ptr = nullptr;
    public:
    explicit unique(T* p = nullptr)
    {
        ptr = p;
    }

    unique(unique& uobj) = delete;
    unique& operator =(unique& uboj) = delete;

    unique(unique&& obj)
    {
        ptr = obj.ptr;
        obj.ptr = nullptr;
    }
    unique& operator = (unique&& obj) noexcept
    {
        if(this != &obj)
        {
            delete ptr;
            ptr = obj.ptr;
            obj.ptr = nullptr;
        }
        return *this;
    }

    T& operator *() const
    {
        return *ptr;
    }
    T* operator ->()const
    {
        return ptr;
    }
    ~unique()
    {
        delete ptr;
        cout<<"memory deleted"<<endl;
    }
    T* get()
    {
        return ptr;
    }
};

int main()
{
    unique<int> p(new int(50));
    cout<<*p<<endl;

    unique<int> p2 = move(p);
    cout<<*p2<<endl;
    if(p.get()==nullptr)
    {
        cout<<"memeory is transfered"<<endl;
    }
}
