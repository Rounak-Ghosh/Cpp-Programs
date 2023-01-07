#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void DFSRes(vector<int> adj[], int source, bool visited[])
{
    visited[source] = true;
    cout << source << " ";
    for(int u : adj[source])
        if(visited[u] == false)
            DFSRes(adj, u, visited);
}

void DFS(vector<int> adj[], int vertex, int source)
{
    bool visited[vertex];
    for(int i=0; i<vertex; i++)
        visited[i] = false;
    DFSRes(adj, source, visited);
}

int main()
{
    // forming graph
    int vertex, edges;
    cin >> vertex >> edges;

    vector<int> adj[vertex];
    int x, y;
    for(int i=0; i<edges; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    DFS(adj, vertex, 0);
    return 0;
}