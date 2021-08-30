#include<iostream>
#include<climits>
using namespace std;

int kadanesalgo(int arr[], int n)
{
    int currSum=0, maxSum=INT_MIN;
    for(int i=0;i<n;i++)
    {
        currSum += arr[i];
        if(currSum < 0)
            currSum = 0;
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

void circularsum(int arr[], int n)
{
    int wrapsum, nonwrapsum;
    nonwrapsum = kadanesalgo(arr, n);

    int totalsum = 0;
    for(int i=0;i<n;i++)
    {
        totalsum += arr[i];
        arr[i] = -arr[i];
    }

    wrapsum = totalsum + kadanesalgo(arr, n);   // arr = -ve array
    cout<<"warpsum = "<<wrapsum<<"\tnonwrapsum = "<<nonwrapsum<<"\ttotalsum = "<<totalsum<<"\tkadane's algo = "<<wrapsum - totalsum<<endl;
    cout<<max(wrapsum, nonwrapsum)<<endl;
}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    circularsum(arr, n);

    return 0;
}