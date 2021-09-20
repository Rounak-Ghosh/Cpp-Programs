#include<iostream>
using namespace std;

bool isSafe(int** arr, int x, int y, int n)
{
    if(x<n && y<n && arr[x][y]==1)
        return true;
    return false;
}

bool ratinMaze(int** arr, int x, int y, int n, int** soln)
{
    if(x==n-1 && y==n-1)
    {
        soln[x][y]=1;
        return true;
    }

    if(isSafe(arr,x,y,n))
    {
        soln[x][y] = 1;
        if(ratinMaze(arr,x+1,y,n,soln))
            return true;
        if(ratinMaze(arr,x,y+1,n,soln))
            return true;
        soln[x][y]=0;   // backtracking
        return false;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;

    int** arr = new int*[n];
    for(int i=0;i<n;i++)
        arr[i]=new int[n];
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> arr[i][j];
    
    int** soln = new int*[n];
    for(int i=0;i<n;i++)
        soln[i]=new int[n];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            soln[i][j]=0;
    
    cout << "\n\n";
    
    if(ratinMaze(arr,0,0,n,soln))
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout << soln[i][j]<<" ";
            cout << endl;
        }    

    return 0;
}