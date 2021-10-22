#include<iostream>
using namespace std;

int main()
{
    long int x, k, minLCM, maxLCM, t;
    cin >> t;
    while(t--)
    {
        cin >> x >> k;
        minLCM = 0;
        maxLCM = 0;
        minLCM = (x*2);
        maxLCM = ( (k*x) * ( (k*x)-1 ) );
        cout << minLCM << " " << maxLCM << endl;
    }
    return 0;
}