#include<iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int arr[n][m];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> arr[i][j];

    cout<<endl;
    int target;
    cin >> target;

    int r = 0, c = m-1;
    bool found = false;
    while(r<n && c>=0 && found == false)
    {
        if(arr[r][c] == target)
            found = true;
        if(arr[r][c] > target)
            c--;
        if(arr[r][c] < target)
            r++;
    }

    if(found == true)
        cout << "\n" << target << " found"<<endl;
    else
        cout<< "\n" << target << " not found"<<endl;

    return 0;
}