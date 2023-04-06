#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*vector<int> findIndegree(vector<int> adj[], int vertex)
{
    vector<int> indegree(vertex);
    for(int i=0; i<vertex; i++)
    {
        for(int x=0; x<adj[i].size(); x++)
        {
            int value = adj[i][x];
            indegree[value]++;
        }
    }

    return indegree;
}*/

void Kahn_Algo(vector<int> adj[], int vertex, vector<int> indegree[])
{
    //vector<int> indegree(vertex);
    //indegree = findIndegree(adj, vertex);
    // we can also find indegree while inputing
    
    queue<int> q;
    for(int i=0; i<vertex; i++)
        if(indegree[i] == 0)
            q.push(i);

    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        cout << x << " ";
        for(auto i : adj[x])
        {
            indegree[i]--;
            if(indegree[i] == 0)
                q.push(i);
        }
    }
}

int main()
{
    int vertex, edges;
    cin >> vertex >> edges;

    vector<int> adj[vertex];
    vector<int> indegree(vertex);
    int x, y;
    for(int i=0; i<edges; i++)
    {
        cin >> x >> y;
        // x -> y
        adj[x].push_back(y); // cuz its directed graph - unidirectional
        indegree[y]++;
    }

    Kahn_Algo(adj, vertex, indegree);
    return 0;
}