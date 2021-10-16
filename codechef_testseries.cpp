#include<iostream>
using namespace std;

int main()
{
    int t, res, ind=0, eng=0;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        ind=0, eng=0;
        for(int r=0; r<5; r++)
        {
            cin >> res;
            if (res == 1)
                ind++;
            else if(res == 2)
                eng++;
        }
        if(ind == eng)
            cout << "DRAW\n";
        else if (ind > eng)
            cout << "INDIA\n";
        else
            cout << "ENGLAND\n";
    }
    return 0;
}