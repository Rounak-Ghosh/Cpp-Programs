#include <iostream>
#include <stack>
using namespace std;

int precedance(char c)
{
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return -1;
}

string infix_to_prefix(string s)
{
    stack<char> st;
    string postfix;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
            postfix = s[i] + postfix;
        else if (s[i] == ')')
            st.push(s[i]);
        else if (s[i] == '(')
        {
            while ((!st.empty()) && st.top() != ')')
            {
                postfix = st.top() + postfix;
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else
        {
            while ((!st.empty()) && (precedance(s[i]) < precedance(st.top())))
            {
                postfix = st.top() + postfix;
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        postfix = st.top() + postfix;
        st.pop();
    }
    return postfix;
}

int main()
{
    cout << infix_to_prefix("(a-b/c)*(a/k-l)");
    return 0;
}