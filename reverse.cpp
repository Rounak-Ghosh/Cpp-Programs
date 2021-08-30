#include<iostream>
using namespace std;


int reverse(int n)
{
    int rev=0;
    int lastdigit;
    while(n>0)
    {
        lastdigit = n%10;
        rev = rev*10 + lastdigit;
        n /= 10;
    }
    return rev;
}

int main()
{
    int n;
    cin>>n;

    cout<<reverse(n);
    return 0;
}