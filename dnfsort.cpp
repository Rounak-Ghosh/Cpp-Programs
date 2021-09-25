#include<iostream>
using namespace std;

int dnfSort(int arr[], int n)
{
    int low=0, high=n-1, mid=0;
    while(mid<=high)
    {
        if(arr[mid]==0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1)
            mid++;
        else if(arr[mid]==2)
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    int arr[] = {1,0,2,1,0,1,2,1,2};
    dnfSort(arr,9);
    for(int i=0; i<9; i++)
        cout << arr[i] << " ";
    return 0;
}