#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &st, int element)
{
    if(st.empty())
    {
        st.push(element);
        return;
    }
    int topElement = st.top();
    st.pop();
    insertAtBottom(st, element);
    st.push(topElement);
}

void reverse(stack<int> &st)
{
    if(st.empty())
        return;

    int element = st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st, element);
}

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    
    cout << "Original Stack" << endl;
    cout << "50 40 30 20 10" << endl;

    reverse(st);

    cout << "Reversed Stack" << endl;
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}