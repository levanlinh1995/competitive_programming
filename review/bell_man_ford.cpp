#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Edge {
    int source, target, weight;
};

bool bellman_ford(const vector<Edge> &graph, vector<int> &dist, vector<int> &path, int source) {
    int V = dist.size();
    int E = graph.size();
    int u, v , w;

    dist[source] = 0;

    for (int i = 1; i <= V - 1 ; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = graph[j].source;
            int v = graph[j].target;
            int w = graph[j].weight;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                path[v] = u;
            }
        }
    }

    for (int i = 0; i < E; i++)
    {
        int u = graph[i].source;
        int v = graph[i].target;
        int w = graph[i].weight;

        if (dist[u] != INF && dist[u] + w < dist[v]) {
            return false;
        }
    }
    
    return true;
}

void printPath(const vector<int> &path, int source, int end) {
    if (source == end) {
        cout << source;
        return;
    }

    if (path[end] == -1) {
        cout << "no found path";
        return;
    }

    vector<int> result;
    result.push_back(end);

    int f = end;

    while (true)
    {
        f = path[f];

        if (f == - 1) {
            break;
        }

        result.push_back(f);

        if (f == source) {
            break;
        }
    }
    
    for (int i = result.size() - 1; i >= 0; i--)
    {
        cout << result[i] << " ";
    }
    
}

int main() {
    freopen("input.txt", "r", stdin);

    int V, E;
    int u, v, w;

    cin >> V >> E;

    vector<Edge> graph(E);
    vector<int> dist(V, INF);
    vector<int> path(V, -1);

    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        graph.push_back(Edge{u, v, w});
    }

    if (bellman_ford(graph, dist, path, 0)) {
        printPath(path, 0, 4);
        cout << endl << dist[4];
    } else {
        cout << "graph contains cycle";
    }

    return 0;
}