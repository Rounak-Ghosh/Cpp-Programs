#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const int N = INT_MAX;
vector<int> parent(N);
vector<int> size(N);

void make_set(int v)
{
    parent[v] = v;
}

void make_set(int v)
{
    parent[v] = v;
    size[v] = 1;
}

int find_set(int v)
{
    if(v == parent[v])
        return v;
    return find_set(parent[v]);
}

int find_set(int v)  // path compression optimisation
{
    if(v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if(a != b) 
        parent[b] = a;
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if(a != b) 
    {
        if(size[a] < size[b])
            swap(a,b);
        parent[b] = a;
        size[a] += size[b];
    }
}

int main() 
{
    for(int i=0; i<N; i++) 
    {
        make_set(i);
    }
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for(int i=0; i<m; i++) 
    {
        int u, v, w;
        cin >> u >> v >> w; // u=edge1 v=edge2 w=cost
        edges.push_back({w, u, v});
    }
    cout << endl;
    sort(edges.begin(), edges.end());
    int cost = 0;
    for(auto i : edges) 
    {
        int w = i[0];
        int u = i[1];
        int v = i[2];
        int x = find_set(u);
        int y = find_set(v);
        if(x == y)
            continue;
        else 
        {
            cout << u << " " << v << "\n";
            cost += w;
            union_sets(u,v);
        }
    }
    cout << cost;
    return 0;
}