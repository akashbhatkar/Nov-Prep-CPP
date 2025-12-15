#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;

        Node(int d)
            :data(d)
             ,next(nullptr)
    {
    }
};

class LinkedList
{
    private:
        Node *head;
    public:
        LinkedList()
            : head(nullptr)
        {
        }

        void Print()
        {
            cout<<"current List"<<endl;
            Node *temp = head;
            while(temp != nullptr)
            {
                cout<<temp->data<<"\t";
                temp = temp->next;
            }
            cout<<endl;
        }

        void InsertAtFirst(int data)
        {
            cout<<"Inserting at first"<<endl;

            Node *temp = head;
            Node *first = new Node(data);
            first->next = temp;
            head = first;
        }

        void InsertAtLast(int data)
        {
            cout<<"Inserting at last"<<endl;        
            Node *last = new Node(data);
            if(head == nullptr)
            {
                head = last;
            }
            else
            {
                Node *temp = head;
                while(temp->next != nullptr)
                {
                    temp = temp->next;
                }
                temp->next = last;
            }
        }

};

int main()
{
    LinkedList list;
    list.InsertAtFirst(10);
    list.Print();
    list.InsertAtFirst(20);
    list.InsertAtFirst(30);
    list.Print();
    list.InsertAtLast(40);
    list.Print();
}
