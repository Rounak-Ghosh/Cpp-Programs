#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int,int>> v;
    for(int i=0; i<n; i++)
    {
        int distFromTown, fuelAtStop;
        cin >> distFromTown >> fuelAtStop;
        v.push_back(make_pair(distFromTown, fuelAtStop));
    }
    int initDist, initFuel;
    cin >> initDist >> initFuel;

    for(int i=0; i<n; i++)
    {
        v[i].first = initDist - v[i].first;
    }

    sort(v.begin(), v.end()); 

    int ans = 0, currFuel = initFuel, flag = 0;
    priority_queue <int, vector<int>> pq;

    for(int i=0; i<n; i++)
    {
        if(currFuel >= initDist)
            break;
        
        while(currFuel < v[i].first)
        {
            if(pq.empty())
            {
                flag = 1;
                break;
            }
            ans ++;
            currFuel += pq.top();
            pq.pop();
        }
        if(flag)
            break;
        pq.push(v[i].second);
    }

    if(flag)
       ans = -1;

    while(!pq.empty() && currFuel < initDist)
    {
        currFuel += pq.top();
        pq.pop();
        ans++;
    }

    if(currFuel < initDist)
        ans = -1;

    cout << ans << endl;

    return 0;
}