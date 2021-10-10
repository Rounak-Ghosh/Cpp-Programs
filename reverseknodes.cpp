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

Node* reverseK(Node* &head, int k)
{
    Node* prevptr = NULL;
    Node* currptr = head;
    Node* nextptr;
    
    int count = 0;
    while(currptr != NULL && count < k)
    {
        nextptr = currptr -> next;
        currptr -> next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }

    if(nextptr != NULL)
        head-> next = reverseK(nextptr, k);

    return prevptr;
}

int main()
{
    Node* head = new Node();

    head -> data = 10;
    head -> next = NULL;
 
    for(int i=20; i<=100; i+=10)
        insertAtEnd(head, i);
    printList(head);

    Node* newhead = reverseK(head,3);
    printList(newhead);

    return 0;
}