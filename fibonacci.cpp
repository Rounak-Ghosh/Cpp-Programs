#include<iostream>
using namespace std;

void fib(int n)
{
    int i, a=0, b=1, c;

    for(i=1;i<=n;i++)
    {
        cout<<a<<" ";
        c=a+b;
        a=b;
        b=c;
    }
}

int main()
{
    int n;
    cin>>n;

    fib(n);

    return 0;
}