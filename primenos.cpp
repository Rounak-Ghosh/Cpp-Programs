#include<iostream>
#include<math.h>
using namespace std;

int main()
{

    int n;
    cout << "Enter range - ";
    cin >> n;
     
    int i,j,c;

    for ( i=2; i<=n; i++)
    {
        c = 0;
        for (j=2; j<=sqrt(n); j++)
        {
            if (i % j == 0)
                break;
            else 
                c = 1;
        }
        if (c==1)
            cout << i << "\n";
    }

    return 0;

}