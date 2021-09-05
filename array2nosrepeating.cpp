#include<iostream>
using namespace std;

int setBit(int n, int pos)
{
    return (( n & (1<<pos)) != 0);      // if == 1, only then return
}

void unique(int arr[], int n)
{
    int xorsum = 0;
    for(int i=0; i<n; i++)
        xorsum = xorsum ^ arr[i];

    int tempxor = xorsum;
    int setbit = 0, pos=0;
    while(setbit!=1)        // finding the position of rightmost setbit
    {
        setbit = xorsum & 1;    // gives last bit
        pos++;
        xorsum = xorsum >> 1;   // updating xorsum
    }

    int newxor = 0;
    for(int i=0; i<n; i++)
        if(setBit(arr[i], pos-1))
            newxor = newxor ^ arr[i];

    cout << newxor << "  " << (tempxor ^ newxor) << endl;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    unique(arr, n);

    return 0;
}