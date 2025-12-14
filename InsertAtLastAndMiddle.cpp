#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node * head = NULL;

void InsertAtFirst(int data)
{
	cout<<"Inserting at first"<<endl;
	Node * temp = new Node();
	temp->data = data;
	temp->next = head;
	head = temp;
}

void InsertBefore(int data, int before)
{
    cout<<"Inserting "<<data<<" Before "<<before<<endl;
    Node *temp = head;
    Node *New = new Node();
    New->data = data;

    // if head is empty
    if(head == NULL)
    {
        cout<<"head is empty"<<endl;
    }
    // Inserting before head
    else if(head->data == before)
    {
        New->next = head;
        head = New;
    }
    else 
    {
        while(temp->next->data != before)
        {
            temp = temp->next;
        }
        New->next = temp->next;
        temp->next = New;
    }
}

void InsertAfter(int data, int after)
{
    cout<<"Inserting "<<data<<" after "<<after<<endl;
    Node *temp = head;
    Node *New = new Node();
    New->data = data;
    if(head == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    while(temp != NULL && temp->data != after)
    {
        temp = temp->next;
    }
    if(temp == NULL)
    {
        cout<<"Value not found"<<endl;
        return;
    }
    New->next = temp->next;
    temp->next = New;
}

void InsertAtLast(int data)
{
    cout<<"Insert At Last"<<endl;
    Node* temp = head;
    Node *last = new Node();
    last->data = data;
    last->next = NULL;
    if(head == NULL)
    {
        head = last;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = last;
    }
    
}
void Print()
{
	Node * temp = head;
	while(temp != NULL)
	{
		cout<<temp->data<<"\t";
		temp = temp->next;
	}
		cout<<endl;
}
int main()
{
	InsertAtFirst(20);
	cout<<"Printing the nodes"<<endl;
	Print();
	
	InsertAtFirst(10);
	Print();
	
	InsertAtFirst(5);
	Print();

    InsertAtLast(30);
    Print();

//InsertAtFirst(1);
    InsertBefore(15, 5);
    Print();

    InsertBefore(25, 30);
    Print();

    InsertAfter(7, 5);
    Print();

    InsertAfter(35, 40);
    Print();

}
