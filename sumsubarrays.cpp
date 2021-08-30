#include<iostream>
using namespace std;

void sumofsubarrays(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        int s = 0;
        for(int j=i;j<n;j++)
        {
            s += arr[j];
            cout<<s<<endl;
        } 
    }
}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    sumofsubarrays(arr, n);
    return 0;
}