#include<iostream>
#include<climits>
#include<math.h>
using namespace std;

void firstrepeating(int arr[], int n)       // Amazon, Oracle
{
    int idx[10];
    for(int i=0; i<10; i++)
        idx[i]=-1;

    int minidx = INT_MAX;

    for(int i=0; i<n; i++)      // Iterating over arr[]
    {
        if(idx[arr[i]]==-1)      // Non-repeating
            idx[arr[i]] = i;
        else                // Repeating
            minidx = min(minidx, idx[arr[i]]);
    }
    cout<<minidx+1<<endl;
}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    firstrepeating(arr, n);
    return 0;
}