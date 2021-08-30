#include<iostream>
#include<climits>
using namespace std;

void kadanesalgo(int arr[], int n)
{
    int currSum=0, maxSum=INT_MIN;
    for(int i=0;i<n;i++)
    {
        currSum += arr[i];
        if(currSum < 0)
            currSum = 0;
        maxSum = max(maxSum, currSum);
    }
    cout<<maxSum<<endl;
}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    kadanesalgo(arr, n);

    return 0;
}