#include<iostream>
using namespace std;

int main()
{
    long int n, k, p, t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        p = 0;
        if(k==1 || k==2)
            p = 2 * (n-k);
        else if (k==3 || k==4)
            p = 2 * (n-k+1);
        else
        {
            if(k%2==1)
                p = 2 * (n-k) + 2 * (k/2);
            else
                p = 2 * (n-k) + 2 * ((k/2)-1);
        }
        cout << p << endl; 
    }
    return 0;
}