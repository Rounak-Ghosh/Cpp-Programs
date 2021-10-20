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
        cout << n->data << "->";
        n = n->next;
    }
    cout << "NULL" << endl;
}

void insertion(Node* &head, int pos, int val)
{
    Node* temp = head;
    pos--;
    while(pos--)
    {
        temp=temp->next;
    }
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = temp->next;
    temp->next = newNode;
}

void deletion(Node* &head, int val)
{
    if(head == NULL)
        return;

    Node* temp = head;
    while(temp->next->data != val)
    {
        temp = temp -> next;
    }
    Node* toDelete = temp -> next;
    temp -> next = temp -> next -> next;

    delete toDelete;
}

void traversing(Node* &head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }            
    cout << endl;
}

void reversing(Node* &head)
{
    Node* temp = head;
    if(temp == NULL)
        return;
    reversing(temp->next);
    cout << temp->data << " ";
}

Node* invert(Node* &head)   
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
    return prevptr;     
}

int main()
{
    // Creating Nodes & creating linked list
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();

    head -> data = 1;
    head -> next = second;
    second -> data = 2;
    second -> next = third;
    third -> data = 3;
    third -> next = fourth;
    fourth -> data = 4;
    fourth -> next = NULL;

    printList(head);            // Printing Linked List             

    insertion(head, 2, 8);      // Inserting "8" at position 2
    printList(head);

    deletion(head, 3);          // Deletion of a node
    printList(head);

    traversing(head);           // Transversing a linked list

    reversing(head);            // Reversing a linked list
    cout << endl;

    Node* newhead = invert(head);   // Inverting a linked list
    printList(newhead);

    return 0;
}