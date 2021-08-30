#include<iostream>
using namespace std;

int linearsearch(int arr[], int n, int key)     // Time Complexity -> O(n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
            return i;
    }
    return -1;
}

int main()
{
    int n;
    cout<<"Enter no of elements - ";
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int key;
    cout<<"Enter key - ";
    cin>>key;
    
    cout<<"Found key at - "<<linearsearch(arr, n, key)<<endl;
    return 0;
}