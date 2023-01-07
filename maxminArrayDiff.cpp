#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0; i<n; i++)
    {
        int in;
        cin >> in;
        v.push_back(in);
    }
    sort(v.begin(), v.end());
    long long mn = 0, mx = 0;
    for(int i=0; i<n/2; i++)
    {
        mx += (v[i+n/2] - v[i]);
        mn += (v[2*i+1] - v[2*i]);
    }
    cout << mx << " " << mn << endl;
    return 0;
}