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

Node* reverse(Node* &head)      // METHOD 1: ITERATIVE WAY
{
    Node* prevptr = NULL;
    Node* currptr = head;
    Node* nextptr;

    while(currptr != NULL)
    {
        nextptr = currptr -> next;
        currptr -> next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;     // new head
}

Node* reverseRecursive(Node* &head)     // METHOD 2: RECURSIVE WAY
{
    if(head == NULL || head -> next == NULL)
        return head;

    Node* newhead = reverseRecursive(head -> next);
    head -> next -> next = head;
    head -> next = NULL;

    return newhead;
}

int main()
{
    Node* head = new Node();

    head -> data = 10;
    head -> next = NULL;
 
    for(int i=20; i<=100; i+=10)
        insertAtEnd(head, i);
    printList(head);

    Node* newhead1 = reverse(head);
    printList(newhead1);

    Node* newhead2 = reverseRecursive(newhead1);
    printList(newhead2);

    return 0;
}