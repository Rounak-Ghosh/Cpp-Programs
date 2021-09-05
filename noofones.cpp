#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int c=0;
    while(n)
    {
        n = (n & n-1);
        c++;
    }

    cout << "No of ones - " << c << endl;
    
    return 0;
}