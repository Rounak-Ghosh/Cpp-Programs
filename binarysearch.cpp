#include<iostream>
using namespace std;

int binarysearch(int arr[], int n, int key)
{
    int s=0, e=n-1;
    // cout<<s<<e;
    while(s<=e)
    {
        int mid = (s+e)/2;

        if(arr[mid]==key)   // Found key 
            return mid; 
        else if(arr[mid]>key)
            e=mid-1;    // Key in first half
        else
            s=mid+1;    // Key in second half       
    }
    return -1;
}

int main()
{
    int n;
    cout<<"Enter no of elements - ";
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)    // Binary search only works for a sorted array
        cin>>arr[i];

    int key;
    cout<<"Enter key - ";
    cin>>key;
    
    cout<<"Found key at - "<<binarysearch(arr, n, key)<<endl;
    return 0;
}