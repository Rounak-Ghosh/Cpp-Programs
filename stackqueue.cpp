#include <iostream>
#include <queue>
using namespace std;

class Stack
{
    public:
    int n;
    queue<int> q1;
    queue<int> q2;
    Stack()
    {
        n = 0;
    }

    void pop()
    {
        if(q1.empty())
        {
            cout<<"Stack is empty"<<endl;
            return;
        }
        while(q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        n--;

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void push(int x)
    {
        q1.push(x);
        n++;
    }

    int top()
    {
        if(q1.empty())
        {
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        while(q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int x = q1.front();
        q2.push(x);

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
        return x;
    }

    int size()
    {   
        return n;
    }
};


int main()
{
    int n;
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    cout << st.size() << endl;
    return 0;
}