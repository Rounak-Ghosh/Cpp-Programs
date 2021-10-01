#include<iostream>
using namespace std;

class Node 
{
public:
    int data;
    Node* next;
};

void printList(Node* n)
{
    while (n != NULL) 
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

void insertAtEnd(Node* &head, int val)
{
    Node* n = new Node();
    n -> data = val;
    if(head == NULL)
    {
        head = n;
        return;
    }    
    Node* last = head;
    while(last -> next != NULL)
        last = last->next;
    last -> next = n;
}

void deleteAtHead(Node* &head)
{
    Node* toDelete = head;
    head = head -> next;
    delete toDelete;
}

void deletion(Node* &head, int val)
{
    if(head == NULL)
        return;

    if(head->next == NULL)
    {
        deleteAtHead(head);
        return;
    }

    Node* temp = head;
    while(temp->next->data != val)
    {
        temp = temp -> next;
    }
    Node* toDelete = temp -> next;
    temp -> next = temp -> next -> next;

    delete toDelete;
}

int main()
{
    Node* head = new Node();

    head -> data = 10;
    head -> next = NULL;
 
    for(int i=20; i<=50; i+=10)
        insertAtEnd(head, i);
    printList(head);
    
    deletion(head, 30);
    printList(head);
    deletion(head, 10);
    printList(head);
    
    return 0;
}