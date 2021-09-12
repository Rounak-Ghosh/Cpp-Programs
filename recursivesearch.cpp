#include<iostream>
using namespace std;

int firstocc(int arr[], int n, int i, int key)
{  
    if(i==n)
        return -1;

    if(arr[i]==key)
        return i;
    
    return firstocc(arr, n, i+1, key);
}

int lastocc(int arr[], int n, int i, int key)
{  
    if(i==n)
        return -1;
    
    int restArray = lastocc(arr, n, i+1, key);
    
    if(restArray!=-1)
    {
        return restArray;
    }

    if(arr[i]==key)
        return i;
    
    return -1;
}

int main()
{
    int n = 7, key = 2;
    int arr[] = {4,2,1,2,5,2,7};

    cout << firstocc(arr, n, 0, key) << endl;
    cout << lastocc(arr, n, 0, key) << endl;

    return 0;
}