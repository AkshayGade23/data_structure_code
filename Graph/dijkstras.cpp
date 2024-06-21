// kruskal's algorithm

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

int main()
{

    int V, E;
    cin >> V >> E;
    vector<int> dist(V, INT_MAX);
    vector<vector<pair<int, int>>> graph(V);
    for (int i = 0; i < E; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        graph[s].push_back({d, w});
        graph[d].push_back({s, w});
    }

    int source;
    cin >> source;
    dist[source] = 0;

    set<pair<int, int>> st;
    st.insert({0, source});

    while (!st.empty())
    {
        auto vertex = *(st.begin());

        st.erase(vertex);

        for (auto i : graph[vertex.second])
        {
            if (dist[i.first] > dist[vertex.second] + i.second)
            {
                st.erase({dist[i.first], i.first});
                dist[i.first] = dist[vertex.second] + i.second;
                st.insert({dist[i.first], i.first});
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (dist[i] < INT_MAX)
            cout << dist[i] << " ";
        else
            cout << -1 << " ";
    }
    return 0;
}

// {0, 1, 2},
//     {0, 3, 7},
//     {0, 4, 5},
//     {1, 2, 1},
//     {1, 4, 4},
//     {2, 3, 3},
//     {2, 4, 2},
//     {3, 4, 5},