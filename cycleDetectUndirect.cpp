#include <iostream>
#include <vector>
using namespace std;

bool iscycle(int source, vector<int> adj[], vector<bool> visited, int parent)
{
    visited[source] = true;
    for(int i : adj[source])
    {
        if(i != parent)
        {
            if(visited[i])
                return true;
            if(!visited[i] && iscycle(i, adj, visited, source))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int vertex, edges;
    cin >> vertex >> edges ;
    vector<int> adj[vertex];

    for(int i=0; i<edges; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    bool cycle = false;
    vector<bool> visited(vertex, false); 
    for(int i=0; i<vertex; i++)
    {
        if(!visited[i] && iscycle(i, adj, visited, -1))
        {
            cycle = true;
        }
    }
    
    if(cycle)
        cout << "Cycle is present";
    else
        cout << "Cycle is absent";
    
    return 0;
}