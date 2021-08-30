#include<iostream>
#include<climits>
using namespace std;

void cummulativesum(int arr[], int n)
{
    int currSum[n+1];   // Array to store cummulative sum
    currSum[0]=0;

    for(int i=1;i<=n;i++)
        currSum[i] = currSum[i-1] + arr[i-1];

    int maxSum = INT_MIN;
    for(int i=1;i<=n;i++)
    {
        int sum=0;
        for(int j=0;j<i;j++)    // Loop to subtrack elements from left-side
        {
            sum = currSum[i] - currSum[j];
            maxSum = max(sum, maxSum);
        }
    }
    
    cout<<maxSum<<endl;
}
int main()          // Cummulative sum approach. For optimised results search Kadane's Algorithm
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cummulativesum(arr, n);

    return 0;
}