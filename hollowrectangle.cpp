#include<iostream>
using namespace std;

int main()
{
    int rows, cols, i, j;
    cout<<"Enter no of rows - ";
    cin>>rows;
    cout<<"Enter no of columns - ";
    cin>>cols;
    cout<<endl;

    for(i=1;i<=rows;i++)
    {
        for(j=1;j<=cols;j++)
        {
            if(i==rows || i==1 || j==1 || j==cols)
                cout<<"*";
            else
                cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}