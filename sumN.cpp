#include<iostream>
using namespace std;

int main()
{

    int n;
    cout << "Enter range (n) - ";
    cin >> n;

    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum = sum + i;
    
    cout << sum;

    return 0;

}