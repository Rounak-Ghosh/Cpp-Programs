#include <iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    node(int val)   // parameterized constructor
    {
        data = val;
        next = NULL;
    }
};

void insertAtTail(node* &head, int val)
{
    node* n = new node(val);

    node* temp = head;
    while(temp -> next != NULL){
        
    }
}

int main()
{

    return 0;
}