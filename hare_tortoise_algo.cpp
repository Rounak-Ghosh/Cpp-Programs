#include<iostream>
using namespace std;

class Node 
{
public:
    int data;
    Node* next;
};

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

void makeCycle(Node* &head, int pos)        // making an cyclic linked list at pos
{
    Node* start = head;
    Node* temp = head;

    int count=1;
    while(temp->next!=NULL)
    {
        if(count == pos)
            start = temp;
        temp = temp->next;
        count++;
    }
    temp->next = start;
}

bool detectCycle(Node* &head)
{
    Node* slow = head;  // tortoise
    Node* fast = head;  // hare

    while(fast!=NULL && fast->next!=NULL)   // Acyclic linked list
    {
        slow = slow->next;
        fast = fast->next->next;

        if(fast==slow)
            return true;
    }
}

int main()          // Floyd's Algo     or      Hare & Tortoise Algo
{
    Node* head = new Node();

    head -> data = 10;
    head -> next = NULL;
 
    for(int i=20; i<100; i+=10)
        insertAtEnd(head, i);       // Regular Linked List

    makeCycle(head, 4);     // Cyclic Linked List

    if(detectCycle(head))
        cout << "Cyclic Linked List";
    else
        cout << "Acyclic Linked List";

    return 0;
}