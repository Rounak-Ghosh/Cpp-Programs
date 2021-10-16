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

void insertAtFront(Node* &head, int val)
{
    Node* n = new Node();
    n -> data = val;
    n -> next = head;
    head = n;
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

int main()
{
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    
    head -> data = 10;
    head -> next = second;
    second -> data = 20;
    second -> next = third;
    third -> data = 30;
    third -> next = NULL;

    /* Possible linked list creation

    head = NULL;
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    insertAtEnd(head, 50);  */
 
    insertAtFront(head, 50);
    insertAtEnd(head, 60);
    printList(head);

    return 0;
}