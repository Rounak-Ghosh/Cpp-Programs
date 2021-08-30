#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number - ";
    cin >> n;
    cout << "\n";

    for (int i=1; i<=10; i++)
        cout << n << " X " << i << " = " << (i*n) << "\n";
    
    return 0;
}