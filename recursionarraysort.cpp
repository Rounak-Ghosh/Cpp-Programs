#include<iostream>
using namespace std;

bool isSort(int arr[], int n)
{
    if(n==1)
        return true;
    else
        return (arr[0]<arr[1] && (isSort(arr+1, n-1)));
}

int main()
{
    int n;
    cin >> n;
    
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];

    cout << isSort(arr,n);
    return 0;
}