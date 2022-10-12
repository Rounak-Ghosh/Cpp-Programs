#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main()
{
    int n, in;
    cin >> n;
    vector<int> a;
    for(int i=0; i<n; i++){
        cin >> in;
        a.push_back(in);
    }
    
    map<int, int> cnt;
    int prefsum = 0;
    for(int i=0; i<n; i++)
    {
        prefsum += a[i];
        cnt[prefsum]++;
    }

    int ans = 0;
    map<int, int> :: iterator it;
    for(it = cnt.begin(); it != cnt.end(); it++)
    {
        int c = it->second;
        ans += (c*(c-1))/2;
        if( it->first == 0)
            ans += it->second;
    }

    cout << ans << endl;
    
    return 0;
}
