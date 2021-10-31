#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

float postfix(string s)
{
    stack<float> st;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]>='0' && s[i]<='9')
            st.push(s[i]-'0');
        else
        {
            float op2 = st.top();
            st.pop();
            float op1 = st.top();
            st.pop();

            switch(s[i])
            {
                case '+': st.push(op1+op2); break;
                case '-': st.push(op1-op2); break;
                case '*': st.push(op1*op2); break;
                case '/': st.push(op1/op2); break;
                case '^': st.push(pow(op1,op2)); break;
            }
        }
    }
    return st.top();
}

int main()
{
    cout << postfix("46+2/5*7+") << endl;
    return 0;
}