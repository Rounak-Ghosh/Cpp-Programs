#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

void printList(Node* head)
{
    Node* temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp != head); 
    cout << endl;
}

void insertAtFront(Node* &head, int val)
{
    
    Node* n = new Node();
    n->data = val;

    if(head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }

    Node* temp = head;

    while(temp->next != head)
        temp = temp->next;
    temp->next = n;
    n->next = head;
    head = n;
}

void insertAtEnd(Node* &head, int val)
{
    if(head == NULL)
    {
        insertAtFront(head, val);
        return;
    }

    Node* n = new Node();
    n->data = val;
    Node* temp = head;

    while(temp->next != head)
        temp = temp->next;

    temp->next = n;
    n->next = head;
}

void deleteAtHead(Node* &head)
{
    Node* temp = head;
    while(temp->next != head)
        temp = temp->next;

    Node* todelete = head;
    temp->next = head->next;
    head = head->next;

    delete todelete;
}

void deletion(Node* &head, int pos)
{
    if(pos == 1)
    {
        deleteAtHead(head);
        return;
    }
    Node* temp = head;
    int count = 1;

    while(count != pos-1)
    {
        temp = temp->next;
        count++;
    }

    Node* todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

int main()
{
    Node* head = new Node();
    head = NULL;

    for(int i=0; i<4; i++)
        insertAtEnd(head, i+1);

    printList(head);

    insertAtFront(head, 5);
    printList(head);    

    deletion(head, 5);
    printList(head);

    return 0;
}
