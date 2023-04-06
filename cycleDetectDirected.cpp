#include <iostream>
#include <vector>
using namespace std;

bool iscycle(int source, vector<int> adj[], vector<bool> visited, vector<int> stack)
{
    stack[source] = true;
    if(!visited[source])
    {
        visited[source] = true;
        for(auto i : adj[source])
        {
            if(!visited[i] and iscycle(i, adj, visited, stack))
                return true;
            if(stack[i])
                return true;
        }
    }
    stack[source] = false;
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
        adj[x].push_back(y); // x -> y
    }

    bool cycle = false;
    vector<int> stack(vertex, 0);
    vector<bool> visited(vertex, false); 
    for(int i=0; i<vertex; i++)
    {
        if(!visited[i] && iscycle(i, adj, visited, stack))
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