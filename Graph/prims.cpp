// prims's algorithm

#include "bits/stdc++.h"
using namespace std;

struct Edge
{
    int destination;
    int weight;
    Edge(int d, int w)
    {
        weight = w;
        destination = d;
    }
};

vector<vector<Edge *>> createGraph(vector<vector<int>> edges, int V)
{
    vector<vector<Edge *>> graph(V);
    for (int i = 0; i < edges.size(); i++)
    {
        vector<int> e = edges[i];
        graph[e[0]].push_back(new Edge(e[1], e[2]));
        graph[e[1]].push_back(new Edge(e[0], e[2]));
    }
    return graph;
}

int main()
{
    int V = 5
    ;
    vector<int> parent(V);
    vector<int> setMst(V, false);
    vector<int> key(V, INT_MAX);

    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 3, 7},
        {0, 4, 5},
        {1, 2, 1},
        {1, 4, 4},
        {2, 3, 3},
        {2, 4, 2},
        {3, 4, 5},
    };

    vector<vector<Edge *>> graph = createGraph(edges, V);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0;
    parent[0] = -1;

    pq.push({0, 0});

    for (int count = 0; count < V - 1; count++)
    {
        int u = pq.top().second;
        pq.pop();
        setMst[u] =true;

        for (auto i : graph[u])
        {   
            int v = i->destination;
            int w = i->weight;

            if (setMst[v] == false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
                pq.push({ key[v],v});
            }
        }
    }

     for (int count = 0; count < V ; count++){
        cout << parent[count] << " " << count << " " << key[count] <<endl;
     }

    return 0;
}