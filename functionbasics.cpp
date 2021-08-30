#include<iostream>
using namespace std;

int sum(int x, int y)
{
    return x+y;
}

int main()
{
    int a,b;
    cin>>a>>b;
    cout<<sum(a,b);
    return 0;
}