#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<int> adj[], int vertex, int source)
{
    queue<int> q;
    vector<bool> visited(vertex);
    for(int i=0; i<vertex; i++)
        visited[i] = false;
    
    visited[source] = true;
    q.push(source);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for(int i : adj[u])
        {
            if(visited[i] == false)
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

//- if graph is disconnected

void BFS_dis(vector<int> adj[], int vertex)
{
    bool visited[vertex]; // int count = 0
    for(int i=0; i<vertex; i++)
        visited[i] = false;
    for(int i=0; i<vertex; i++)
        if(visited[i] == false)
            BFS(adj, i, visited[]);
    // void BFS(vector<int> adj, int source, int visited[])
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

    BFS(adj, vertex, 0);
    return 0;
}