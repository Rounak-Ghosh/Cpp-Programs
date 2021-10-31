#include <iostream>
#include <stack>
using namespace std;

int precedence(char c)
{
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else        // when '(' or ')'
        return -1;
}

string infix_to_postfix(string infix)
{
    stack<char> s;
    string postfix;
    for(int i = 0; i < infix.length(); i++)
    {
        if(infix[i] >='a' && infix[i] <= 'z')
            postfix += infix[i];
        else if(infix[i] == '(')
            s.push(infix[i]);
        else if(infix[i] == ')')
        {
            while(!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
        else    // if -> operator
        {
            while(!s.empty() && precedence(s.top()) >= precedence(infix[i]))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(infix[i]);
        }
    }

    while(!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main()
{
    cout << infix_to_postfix("(a-b/c)*(a/k-l)") << endl;
    return 0;
}