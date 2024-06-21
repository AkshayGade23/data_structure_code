#include "bits/stdc++.h"
using namespace std;
int const N = 1e5 + 6;
vector<int> parent(N);
vector<int> sz(N);

void make_set()
{
    for (int i = 0; i < N; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
}

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

int union_sets(int src, int dest)
{
    src = find_set(src);
    dest = find_set(dest);

    if (src != dest)
    {
        if (sz[src] < sz[dest])
            sw ap(src, dest);
        parent[dest] = src;
        sz[src] += sz[dest];
    }
}

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

void isCycle(vector<Edge *> edges)
{
    for (auto edge : edges)
    {
        int x = find_set((edge->source));
        int y = find_set((edge->destination));

        if (x == y)
            cout << "detected cycle in graph;" << edge->source << "-" << edge->destination << endl;

        else
            union_sets(edge->source, edge->destination);
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

    make_set();
    isCycle(edges);
    return 0;
}