#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

float prefix(string s)
{
    stack<float> st;
    for(int i=s.length()-1; i>=0; i--)
    {
        if(s[i]>='0' && s[i]<='9')
            st.push(s[i]-'0');
        else
        {
            float op1 = st.top();
            st.pop();
            float op2 = st.top();
            st.pop();

            switch(s[i])
            {
                case '+': st.push(op1+op2); break;
                case '-': st.push(op1-op2); break;
                case '*': st.push(op1*op2); break;
                case '/': st.push(op2/op1); break;
                case '^': st.push(pow(op2,op1)); break;
            }
        }
    }
    return st.top();
}

int main()
{
    cout << prefix("-+7*45+20") << endl;
    return 0;
}