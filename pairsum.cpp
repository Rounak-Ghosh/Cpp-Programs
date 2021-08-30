#include<iostream>
#include<climits>
using namespace std;

bool pairsum(int arr[], int n, int k)
{
    int low=0, high=n-1;
    
    while(low<high)
    {
        if(arr[low] + arr[high] == k)
        {
            cout<<low<<" "<<high<<endl;
            return true;
        }
        else if(arr[low] + arr[high] > k)
            high--;
        else
            low++;
    }
    return false;

}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    int k;
    cin>>k;

    pairsum(arr, n, k);

    return 0;
}