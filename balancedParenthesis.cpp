#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s)
{
    int n = s.length();
    stack<char> st;
    bool ans = true;
    for(int i=0; i<n; i++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else if(s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if(st.empty())
                return false;
            else if(s[i] == ')' && st.top() == '(')
                st.pop();
            else if(s[i] == '}' && st.top() == '{')
                st.pop();
            else if(s[i] == ']' && st.top() == '[')
                st.pop();
            else
                return false;
        }
    }
    if(st.empty())
        return true;
    else
        return false;
}

int main()
{
    string s = "[({)}]";
    if(isValid(s))
        cout<<"Balanced";
    else
        cout<<"Not Balanced";
    return 0;
}