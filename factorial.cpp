#include<iostream>
using namespace std;

int factorial(int n)
{
    int prod=1;
    for(int i=1;i<=n;i++)
        prod *= i;
    return prod;
}

int main()
{
    int n;
    cin>>n;
    cout<<factorial(n);
    return 0;
}