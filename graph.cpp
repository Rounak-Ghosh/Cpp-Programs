#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAdjList(vector<int> adj[], int vertex)
{
    for(int i=0; i<vertex; i++)
    {
        for(int x=0; x<adj[i].size(); x++)
        {
            cout << adj[i][x] << " ";
        }
        cout << endl;
    }
}

/*
int main()
{
    int v = 4;
    vector<int> adj[v];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    
    printAdjList(adj);

    return 0;
}
*/

int main()
{
    int vertex, edges;
    cin >> vertex >> edges;
    vector<int> adj[vertex];
    // input the links for the graph
    for(int i=0; i<edges; i++)
    {
        int x, y;
        cin >> x >> y;
        addEdge(adj, x, y);
    }
    cout << endl;
    printAdjList(adj, vertex);
    return 0;
}
