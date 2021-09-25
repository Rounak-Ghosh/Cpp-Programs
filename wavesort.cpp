#include<iostream>
using namespace std;

void swap(int a[], int x, int y)
{
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}

void waveSort(int arr[], int n)
{
    for(int i=1; i<n; i+=2)
    {
         if(arr[i]>arr[i-1])
            swap(arr, i, i-1);
        if(arr[i]>arr[i+1] && i<=n-2)
            swap(arr, i, i+1);
    }
}

void adding(int sum[], int a, int b)
{
    sum[0] = a+b;
}

int main()
{
    int arr[] = {1,3,4,7,5,6,2};
    waveSort(arr, 7);
    for(int i=0; i<7; i++)
        cout << arr[i] << " ";

    int a=5, b=7, sum[1] = {0};
    adding(sum,a,b);
    cout << "\n" << sum[0];
    return 0;
}