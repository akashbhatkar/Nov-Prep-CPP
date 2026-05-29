#include<iostream>
using namespace std;
class myvector
{
    private:
    int capacity, size, *arr;
    void resize()
    {
        capacity = capacity *2;
        int *temp = new int[capacity];
        for(int i= 0; i<size; i++)
        {
            temp[i] = arr[i];
        }
        delete []arr;
        arr = temp;
    }
    public:
    myvector()
    {
        capacity = 2;
        size = 0;
        arr = new int[capacity];
    }
    void push_back(int value)
    {
        if(size == capacity)
        {
            resize();
        }
        arr[size] = value;
        size++;
    }
    void pop_back()
    {
        if(size>0)
        {
            size--;
        }
    }
    int getsize(){return size;}
    int getcapacity(){return capacity;}
    void Display()
    {
        for(int i=0;i<size;i++)
        {
            cout<<arr[i]<<"\t";
        }
        cout<<endl;
    }
    ~myvector(){delete []arr;}
};
int main()
{
    myvector v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(20);
    v.Display();

    cout<<"capacity = "<<v.getcapacity()<<endl;
    cout<<"size = "<<v.getsize()<<endl;
    v.pop_back();
    v.Display();
    
    cout<<"capacity = "<<v.getcapacity()<<endl;
    cout<<"size = "<<v.getsize()<<endl;
}
