#include<iostream>
#include<cmath>
using namespace std;

class Node 
{
    public:
    int data;
    Node* next;
};

void printList(Node *n)
{
    while(n != NULL)
    {
        cout << n->data << "->";
        n = n->next;
    }
    cout << "NULL";
}

void insertAtEnd(Node* &head, int val)
{
    Node* n = new Node();
    n->data = val;
    if(head == NULL)
    {
        head = n;
        return;
    }
    Node* last = head;
    while(last->next != NULL)
        last = last->next;
    last->next = n;
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

int intersection(Node* &head1, Node* &head2)
{
    int l1 = length(head1);
    int l2 = length(head2);
    int d = abs(l1-l2);
    Node* ptr1;     // bigger list
    Node* ptr2;     // shorter list
    if(l1>l2)
    {
        ptr1 = head1;
        ptr2 = head2;
    }
    else
    {
        ptr1 = head2;
        ptr2 = head1;
    }

    while(d--)
    {
        ptr1 = ptr1->next;
        if(ptr1 == NULL)    // If any list turns out to be NULL
            return -1;
    }

    while(ptr1 != NULL && ptr2 != NULL)
    {
        if(ptr1 == ptr2)
            return ptr1->data;
  
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}

void intersect(Node* &head1, Node* &head2, int pos)
{
    Node* temp1 = head1;
    Node* temp2 = head2;
    pos--;
    while(pos--)        // Navigating to point of merger
        temp1 = temp1->next;
    while(temp2->next != NULL)  // Navigating to end of list 2
        temp2 = temp2->next;
    temp2->next = temp1;      // Merging
}

int main()
{
    Node* head1 = new Node();
    Node* head2 = new Node();
    
    head1 = NULL;
    head2 = NULL;

    for(int i=0; i<6; i++)      // list 1
        insertAtEnd(head1, i+1);
    
    for(int i=7; i<9; i++)      // list 2
        insertAtEnd(head2, i+1);
    
    intersect(head1, head2, 5);

    printList(head1);
    cout << endl;
    printList(head2);
    cout << endl;
    int x = intersection(head1, head2);
    cout << head1->data << " , " << head2->data << endl;
    cout << x;
    return 0;
}