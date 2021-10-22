#include<iostream>
using namespace std;

int main()
{
    int t, x, y, i, count;
    cin >> t;
    while(t--)
    {
        cin >> x >> y;
        count=0;
        while(x!=y)
        {
            if(x<y)
            {
                x+=2;
                count++;
            }
            if(x>y)
            {
                x-=1;
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}


/*
while(t--)
    {
        count=0;
        cin >> x >> y;
        for(i=x+2; i<=y+1; i+=2)
        {
            count++;
        }
        i-=2;
        if(i==y+1)
            count++;
        cout << count << endl;
    }
*/