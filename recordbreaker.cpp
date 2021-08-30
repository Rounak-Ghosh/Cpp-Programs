#include<iostream>
#include<math.h>
using namespace std;

void recordday(int arr[], int n)            // GOOGLE KICKSTART PROBLEM
{
    int mx = -1, ans = 0;
    for(int i=0;i<n;i++)                    // Alternate Solution : Increase length of array by 1, and manually insert -1 as last element.
    {
        if(arr[i]>mx && arr[i]>arr[i+1] && i<n-1)
        {
            mx = max(mx, arr[i]);
            ans++;
        }    
        
        else if(arr[i]>mx && i==n-1)
        {
            mx = max(mx, arr[i]);
            ans++;
        }
    }
    cout<<ans<<endl;
}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    recordday(arr, n);
    return 0;
}