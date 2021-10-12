#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* prev;
};

void insertAtHead(Node* &head, int val)
{
    Node* n = new Node();
    n->data = val;
    n->next = head;
    if(head != NULL)
        head-> prev = n;
    head=n;
}

void insertAtEnd(Node* &head, int val)
{    
    if(head == NULL)
    {
        insertAtHead(head,val);
        return;
    }

    Node* n = new Node(); 
    n->data = val;

    Node* last = head;
    while(last->next != NULL)
        last = last->next;
    
    last->next = n;
    n->prev = last;
}

void printList(Node* n)
{
    while (n != NULL) 
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

void deleteAtHead(Node* &head)
{
    Node* toDelete = head;
    head = head->next;
    head->prev = NULL;
    delete toDelete;
}

void deletion(Node* &head, int pos)
{   
    if(pos==1)
    {
        deleteAtHead(head);
        return;
    }

    Node* temp = head;
    int count=1;
    while(temp != NULL && count != pos)
    {
        temp = temp->next;
        count++;
    }
        
    temp->prev->next = temp->next;
    
    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
}

int main()
{
    Node* head = new Node();
    head = NULL;

    for(int i=1; i<=8; i++)
        insertAtEnd(head, i*10);    
    insertAtHead(head, 0);
    
    printList(head);
    deletion(head,1);
    printList(head);
    return 0;
}