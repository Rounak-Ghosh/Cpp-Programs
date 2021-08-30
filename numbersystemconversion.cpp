#include<iostream>
#include<math.h>
using namespace std;


void bindec(int n)
{
    int x=1, ans=0;
    while(n>0)
    {
        int y = n%10;
        ans += y*x;
        x *=2;
        n /= 10;
    }
    cout<<"Ans = "<<ans<<endl;
}

void octdec(int n)
{
    int x=1, ans=0;
    while(n>0)
    {
        int y = n%10;
        ans += y*x;
        x *=8;
        n /= 10;
    }
    cout<<"Ans = "<<ans<<endl;
}

void hexdec(int n)  // ABCDEF not assigned
{
    int x=1, ans=0;
    while(n>0)
    {
        int y = n%10;
        ans += y*x;
        x *=16;
        n /= 10;
    }
    cout<<"Ans = "<<ans<<endl;
}

void decbin(int n)
{
    int x=1,ans=0;
    while(x<=n)
        x *= 2;
    x /= 2;
    while(x>0)
    {
        int lastdigit = n/x;
        n -= lastdigit*x;
        x /= 2;
        ans = ans*10 + lastdigit;
    }
    cout<<"Ans = "<<ans<<endl;    
}

void decoct(int n)
{
    int x=1,ans=0;
    while(x<=n)
        x *= 8;
    x /= 8;
    while(x>0)
    {
        int lastdigit = n/x;
        n -= lastdigit*x;
        x /= 8;
        ans = ans*10 + lastdigit;
    }
    cout<<"Ans = "<<ans<<endl;
}

void dechex(int n)  // ABCDEF not assigned
{
    int x=1,ans=0;
    while(x<=n)
        x *= 16;
    x /= 16;
    while(x>0)
    {
        int lastdigit = n/x;
        n -= lastdigit*x;
        x /= 16;
        ans = ans*10 + lastdigit;
    }
    cout<<"Ans = "<<ans<<endl;
}

int main()
{
    int n, ch;
    cout<<"1> Binary to Decimal\n2> Octal to Decimal\n3> Hexadecimal to Decimal\n4> Decimal to Binary\n5> Decimal to Octal\n6> Decimal to Hexadecimal\n";
    cout<<"Enter your choice - ";
    cin>>ch;
    cout<<"Enter the value - ";
    cin>>n;
    switch(ch)
    {
        case 1: bindec(n);
        case 2: octdec(n);
        case 3: hexdec(n);
        case 4: decbin(n);
        case 5: decoct(n);
        case 6: dechex(n);
    }
    return 0;
}