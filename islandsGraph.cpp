#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<int> adj[], int source, bool visited[])
{
    queue<int> q;

    visited[source] = true;
    q.push(source);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
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

int noOfIslands(vector<int> adj[], int vertex)
{
    int count = 0;
    bool visited[vertex];
    for(int i=0; i<vertex; i++)
        visited[i] = false;
    for(int i=0; i<vertex; i++)
    {
        if(visited[i] == false)
        {
            BFS(adj, i, visited);
            count++; 
        }
    }
    return count;    
}

int main()
{
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

    int count = noOfIslands(adj, vertex);

    cout << "Islands  = " << count ;

    return 0;
}