#include<iostream>
using namespace std;

#define n 100

class stack
{
    int *arr;
    int top;
    
    public:
    stack()
    {
        arr = new int[n];
        top = -1;
    }

    void push(int x)
    {
        if(top == n-1)
        {
            cout<<"Stack Overflow"<<endl;
            return;
        }
        arr[++top] = x;
    }

    void pop()
    {
        if(top == -1)
        {
            cout<<"Stack Underflow"<<endl;
            return;
        }
        top--;
    }

    int Top()
    {
        if(top == -1)
        {
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

int main()
{
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.Top() << endl;
    s.pop();    // 30 poped
    cout << s.Top() << endl;
    s.pop();    // 20 poped
    cout << s.Top() << endl;
    s.pop();    // 10 poped
    cout << s.isEmpty() << endl;
    return 0;
}