#include<iostream>
using namespace std;

int merge(int arr[], int l, int mid, int r)
{
    int inv = 0;
    int n1 = mid - l + 1;
    int n2 = r - mid;
    
    int a[n1];
    int b[n2];

    for(int i=0; i<n1; i++)     // temp array a
        a[i] = arr[l+i];
    
    for(int i=0; i<n2; i++)     // temp array b
        b[i] = arr[mid+1+i];

    int i=0, j=0, k=l;
    while(i < n1 && j < n2)     // comaparing both arrays, if i or j reaches the last element, while terminates
    {
        if(a[i] <= b[j])
        {
            arr[k] = a[i];
            i++;
        }    
        else    // a[i], a[i+1], a[i+2] .... > b[j] and i<j
        {
            arr[k] = b[j];
            j++;
            inv += n1 - i;
        }
        k++;
    }

    while(i < n1)       // if while terminates due to j==n2, this assignes the rest of elements in a array
    {
        arr[k] = a[i];
        i++; k++;
    }
    
    while(j < n2)       // if while terminates due to i==n1, this assignes the rest of elements in a array
    {
        arr[k] = b[j];
        j++; k++;
    }
    return inv;
}

int mergeSort(int arr[], int l, int r)
{
    int inv = 0;
    if(l < r)
    {
        int mid = (l + r) / 2;
        inv += mergeSort(arr, l, mid);
        inv += mergeSort(arr, mid+1, r);
        inv += merge(arr, l, mid, r);
    }
    return inv;
}

int main()
{
    int arr[] ={3,5,6,9,1,2,7,8};
    cout << mergeSort(arr,0,7);
    return 0;
}