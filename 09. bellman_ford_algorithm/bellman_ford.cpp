#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int INF = 1e9;

struct Edge
{
    int source;
    int target;
    int weight;
};

bool bellman_ford(vector<Edge> &graph, vector<int> &dist, vector<int> &path, int source) {
    int V = dist.size();
    int E = graph.size();

    dist[source] = 0;
    int u, v, w;

    for (int i = 1; i <= V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            u = graph[j].source;
            v = graph[j].target;
            w = graph[j].weight;

            if (dist[u] != INF && (dist[u] + w < dist[v])) {
                dist[v] = dist[u] + w;
                path[v] = u;
            }
        }
    }

    for (int j = 0; j < E; j++)
    {
        u = graph[j].source;
        v = graph[j].target;
        w = graph[j].weight;

        if (dist[u] != INF && (dist[u] + w < dist[v])) {
            return false;
        }
    }

    return true;
    
}

int main() {
    int s, t, V, E;
    int u, v, w;

    cin >> V >> E;

    vector<int> dist(V, INF);
    vector<int> path(V, -1);
    vector<Edge> graph;

    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        Edge e = {u, v, w};
        graph.push_back(e);
    }

    s = 0;
    t = 4;

    bool temp = bellman_ford(graph, dist, path, s);
    if (temp == false) {
        cout << "Graph contains negative weight cycle";
    } else {
        cout << dist[t];
    }
    
    return 0;
}