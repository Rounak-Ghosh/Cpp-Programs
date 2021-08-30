#include<iostream>
using namespace std;

int subarraysum(int arr[], int n, int sum)          // Facebook, Google, Amazon, VISA
{
    int curr_sum = 0, start = 0, i;
 
    for (i = 0; i < n; i++) 
    {
        while (curr_sum > sum && start < i - 1) 
        {
            curr_sum -= arr[start];
            start++;
        }
 
        if (curr_sum == sum) 
        {
            cout << "Sum found between indexes "
                 << start << " and " << i - 1;
            return 1;
        }
        
        curr_sum += arr[i];
    }
 
    cout << "No subarray found";
    return 0;
}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int sum;
    cin>>sum;

    subarraysum(arr, n, sum);

    return 0;
}