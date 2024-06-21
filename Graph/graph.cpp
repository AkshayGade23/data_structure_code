#include "bits/stdc++.h"
using namespace std;

struct Edge
{
    int source;
    int destination;
    Edge(int s, int d)
    {
        source = s;
        destination = d;
    }
};

vector<vector<Edge *>> createGraph(vector<Edge *> edges, int V)
{
    vector<vector<Edge *>> graph(V);
    for (int i = 0; i < edges.size(); i++)
    {
        Edge *e = edges[i];
        graph[e->source].push_back(e);
    }
    return graph;
}

void BSF(vector<vector<Edge *>> graph, int V, int startNode)
{
    vector<bool> visited(V, false);

    queue<int> q;
    q.push(startNode);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        if (!visited[node])
        {
            cout << node << " ";
            visited[node] = true;

            for (int i = 0; i < graph[node].size(); i++)
                q.push(graph[node][i]->destination);
        }
    }
}

int main()
{
    int V = 7;

    vector<Edge *> edges = {
        new Edge(0, 1),
        new Edge(0, 2),
        new Edge(1, 3),
        new Edge(2, 4),
        new Edge(3, 4),
        new Edge(3, 5),
        new Edge(4, 5),
        new Edge(5, 6),
    };

    vector<vector<Edge *>> graph = createGraph(edges, V);
    cout << "Breadth First Search : ";
    BSF(graph, V, 0);
    return 0;
}