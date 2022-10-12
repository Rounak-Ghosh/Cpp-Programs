#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> deno(n);
    for(int i=0; i<n; i++)
    {
        int in;
        cin >> in;
        deno.push_back(in);
    }

    int amount;
    cin >> amount;

    sort(deno.begin(), deno.end(), greater<int>());

    int ans = 0;
    for(int i=0; i<n; i++)
    {
        ans += amount / deno[i];
        amount -= (amount / deno[i]) * deno[i];
    }

    cout << ans;

    return 0;
}