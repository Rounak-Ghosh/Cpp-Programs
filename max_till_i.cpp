#include<iostream>
#include<math.h>
#include<climits>
using namespace std;

void maxtilli(int arr[], int n)
{
    int mx = INT_MIN;
    for(int i=0;i<n;i++)
    {
        int mx = max(mx, arr[i]);
        cout<<mx<<endl;
    }
}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    maxtilli(arr, n);
    return 0;
}