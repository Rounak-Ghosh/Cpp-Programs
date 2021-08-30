#include<iostream>
#include<math.h>
using namespace std;

bool isarmstrong(int n)
{
    int sum=0, r, m=n;
    
    while(m>0)
    {
        r = m%10;
        sum = sum + int(pow(r,3));
        m /= 10;
    }

    if(sum == n)
        cout<<"Armstrong";
    else 
        cout<<"Not Armstrong";
    return 0; 
}

int main()
{
    int n;
    cin>>n;

    isarmstrong(n);
   
    return 0;
}