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

int length(Node* &head)
{
    int l=0;
    Node* temp = head;
    while(temp != NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}

Node* kAppend(Node* &head, int k)
{
    Node* newHead;
    Node* newTail;
    Node* tail = head;
    
    int l = length(head);
    int count = 1;
    while(tail->next != NULL)
    {
        if(count == l-k)
        {
            newTail = tail;
            newHead = tail->next;
        }
        tail=tail->next;
        count++;
    }

    newTail->next = NULL;
    tail->next = head;

    return newHead;
}

int main()
{
    Node* head = new Node();
    head =  NULL;

    for(int i=1; i<=6; i++)
        insertAtEnd(head, i*10);
    printList(head);

    Node* newHead = kAppend(head, 4);
    printList(newHead);
    return 0;
}