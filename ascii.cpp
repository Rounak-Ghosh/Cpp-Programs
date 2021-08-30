#include<iostream>
using namespace std;

int findAscii(int ch)
{
    return int(ch);       // Python -> ord(ch)     Java  int ascii = ch;      C printf("%d",c)
}

int main()
{
    char ch;
    cin>>ch;
    cout<<findAscii(ch);
    return 0;
}