#include<iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r)
{
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
        if(a[i] < b[j])
        {
            arr[k] = a[i];
            i++;
        }    
        else
        {
            arr[k] = b[j];
            j++;
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
}

void mergeSort(int arr[], int l, int r)
{
    if(l < r)
    {
        int mid = ( l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);

        merge(arr, l, mid, r);
    }
}

int main()
{
    int arr[] = { 6, 3, 9, 5, 2, 8, 7, 1};
    mergeSort(arr, 0, 8);
    for(int i=0; i<8; i++)
        cout << arr[i] << " ";
    return 0;
}