#include<iostream>
#include<climits>
#include<math.h>
using namespace std;

int main()
{
    int i,n;
    cout<<"Enter no of elememnts - ";
    cin>>n;

    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];

    int minNo = INT_MAX;    // Maximum no possible in Integer system
    int maxNo = INT_MIN;    // Minimum no possible in Integer system

    for (i=0;i<n;i++)
    {
        maxNo = max(maxNo,arr[i]);
        minNo = min(minNo,arr[i]);
    }
    cout<<"Max element = "<<maxNo<<endl;
    cout<<"Min element = "<<minNo<<endl;
    return 0;
}