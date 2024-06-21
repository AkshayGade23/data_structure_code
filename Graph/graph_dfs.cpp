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
        graph[e->destination].push_back(new Edge(e->destination, e->source));
    }
    return graph;
}


vector<vector<int>> createGraph(vector<vector<int>>& edges, int V)
{
    vector<vector<int>> graph(V);
    for (int i = 0; i < edges.size(); i++)
    {
        graph[edges[i][0]] =  {edges[i][1],edges[i][2]};
        graph[edges[i][1]] =  {edges[i][0],edges[i][2]};
    }
    return graph;
}


void BFS(vector<vector<Edge *>> graph, int V, int startNode)
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


void DFS(vector<vector<Edge *>> graph, vector<bool> visited, int current)
{
    stack<int> s;
    s.push(current);

    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        if (!visited[node])
        {
            cout << node << " ";
            visited[node] = true;
            for (int i = 0; i < graph[node].size(); i++)
                s.push(graph[node][i]->destination);
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
    vector<bool> visited(V, false);
    cout << "Depth First Search : ";
    DFS(graph, visited, 0);
    return 0;
}