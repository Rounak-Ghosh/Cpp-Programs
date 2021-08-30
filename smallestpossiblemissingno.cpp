#include<iostream>
using namespace std;

void missingno(int arr[], int n)        // Accolite, Amazon, Samsung, Snapdeal
{
    int check[10], i;
    for(i=0;i<10;i++)
        check[i] = 0;
    
    for(i=0;i<n;i++)
    {
        if(arr[i] >= 0)
            check[arr[i]] = 1;
    }

    i=0;
    while(check[i] == 1)
        i++;

    cout<<i<<endl;
}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    missingno(arr, n);

    return 0;
}