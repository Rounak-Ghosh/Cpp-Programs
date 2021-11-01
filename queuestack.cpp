#include <iostream>
#include <stack>
using namespace std;

class queue     // may collide with inbuilt queue class
{
    stack<int> s1;
    stack<int> s2;

    public:
    void push(int x)
    {
        s1.push(x);
    }

    void pop()
    {
        if(s1.empty() && s2.empty())
        {
            cout<<"Queue underflow"<<endl;
            return;
        }
        
        else if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }

    int top()
    {
        if(s1.empty() && s2.empty())
        {
            cout<<"Queue underflow"<<endl;
            return -1;
        }
        
        else if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
        return s2.top();
    }

    bool empty()
    {
        if(s1.empty() && s2.empty())
            return true;
        return false;
    }
};

int main()
{
    queue q;
    q.push(2);
    q.push(5);
    q.push(3);
    cout << q.top() << endl;
    q.pop();
    q.push(6);
    q.pop();
    q.pop();
    cout << q.top() << endl;
    return 0;
}