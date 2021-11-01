#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class queue
{
    Node* front;
    Node* back;

    public:
    queue()
    {
        front = NULL;
        back = NULL;
    }

    void enqueue(int x)
    {
        Node* n = new Node();
        n->data = x;

        if(front == NULL)
        {
            front = n;
            back = n;
            return;
        }
        back->next = n;
        back = n;
        // back->next = NULL; why ??? not includede by apna college
    }

    void dequeue()
    {
        if(front == NULL)
        {
            cout << "Queue underflow" << endl;
            return;
        }
        Node* todelete = front;
        front = front->next;
        delete todelete;
    }

    int peek()
    {
        if(front == NULL)
        {
            cout << "Queue underflow" << endl;
            return -1;
        }
        return front->data;
    }

    bool empty()
    {
        if(front == NULL)
            return true;
        return false;
    }
};

int main()
{
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek()<<endl;   
    q.dequeue();
    cout << q.empty() << endl;
    return 0;
}