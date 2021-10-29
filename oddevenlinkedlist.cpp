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

void evenAfterOdd(Node* &head)      // Nodes not values
{
    Node* odd = head;
    Node* even = head->next;
    Node* evenStart = even;
    while(odd->next != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenStart;
    if(odd->next == NULL)
        even->next = NULL;
}

int main()
{
    Node* head = NULL;
    for(int i=1; i<10; i++)
        insertAtEnd(head, i);
    printList(head);
    evenAfterOdd(head);
    printList(head);
    return 0;
}