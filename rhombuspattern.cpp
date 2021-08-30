#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter no of rows - ";
	cin>>n;
    int i,j;
    for(i=1;i<=n;i++)
    {
	    for(j=1;j<=n-i;j++)
	        cout<<" ";
	    for(j=1;j<=n;j++)
	    {
	        if(j==1 || j==n || i == 1 || i == n)
	            cout<<"*";
	        else
	            cout<<" ";
	    }      
	    cout<<endl;
	}
}