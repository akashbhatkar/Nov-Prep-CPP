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
/*	Node * temp = new Node();
	temp->data = data;
	if(head != NULL)
	{
		Node* temp1 = new Node();
		temp1 = head;
		temp->data = data;
		temp->next = temp1;
		head = temp;
	}
	else
	{
		temp->next = NULL;
		head = temp;
	}
*/
cout<<"Inserting at first"<<endl;
Node * temp = new Node();
temp->data = data;
temp->next = head;
head = temp;
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
	
	
}
