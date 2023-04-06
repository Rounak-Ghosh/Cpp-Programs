#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>
using namespace std;

int vertex, edge;
const int N = 1e5+3;
vector<vector<int>> adj[N];
int cost = 0;
vector<int> dist(N), parent(N);
vector<bool> visited(N);

void primsMST(int source)
{
    for(int i=1; i<N; i++)
    {
        dist[i] = INT_MAX;
    }
    set<vector<int>> s;
    dist[source] = 0;
    s.insert({0, source});
    while(!s.empty()) // set empty hoye jacche tau result asche na
    
    {
        auto x = *(s.begin());
        s.erase(x);
        visited[x[1]] = true;
        int u = x[1];
        int v = parent[x[1]];
        int w = x[0];
        cout << u << " " << v << " " << w << "\n";
        cost += w;
        for(auto it: adj[x[1]])
        {
            cout << it[0] <<" "<< it[1] << " : " << visited[it[0]] << "\n";
            if(visited[it[0]])
            {
                cout << "Bhanga" << it[0] <<" "<< it[1] << " : " << visited[it[0]] << "\n";
                continue;
            }
            if(dist[it[0] > it[1]])
            {
                s.erase({dist[it[0]], it[0]});
                dist[it[0]] = it[1];
                s.insert({dist[it[0]], it[0]});
                parent[it[0]] = x[1];
            }
        }
    }
}

int main()
{
    cin >> vertex >> edge;
    for(int i=0; i<edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w; // u=edge1 v=edge2 w=cost
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    primsMST(0);
    cout << cost;
    return 0;
}