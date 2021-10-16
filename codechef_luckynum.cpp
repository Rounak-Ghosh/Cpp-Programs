#include<iostream>
using namespace std;

int main()
{
    int t, a, b, c;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        cin >> a >> b >> c;
        if((a==7) || (b==7) || (c==7))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}