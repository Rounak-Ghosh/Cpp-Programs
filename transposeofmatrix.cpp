#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int arr[n][n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>arr[i][j];

    int temp;
    for(int i=0; i<n; i++)
        for(int j=i; j<n; j++)
        {
            temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }

    cout<<endl;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    
    return 0;
}