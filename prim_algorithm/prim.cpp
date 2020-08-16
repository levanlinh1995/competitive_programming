#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int printDist(const vector<int> &dist) {
    int sum = 0;
    for (int i = 0; i < dist.size(); i++)
    {
        if (dist[i] != INF) {
            sum+= dist[i];
        }
    }
    

    return sum;
}

void printEdges(const vector<int> &path, const vector<int> &dist) {
    for (int i = 0; i < path.size(); i++)
    {
        if (path[i] != -1) {
            cout << path[i] << " - " << i << ": " << dist[i] << endl;
        }
    }
}


void prim(const vector<vector<pair<int, int>>> &graph, vector<int> &dist, vector<bool> &visited, vector<int> &path, int source) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push(make_pair(0, source));
    dist[source] = 0;

    while (!pq.empty())
    {
        pair<int, int> top = pq.top();
        pq.pop();

        int u = top.second;
        visited[u] = true;

        for (int i = 0; i < graph[u].size(); i++)
        {
            pair<int, int> nei = graph[u][i];
            int v = graph[u][i].second;
            int w = graph[u][i].first;

            if (!visited[v] && dist[v] > w) {
                dist[v] = w;
                path[v] = u;
                pq.push(make_pair(w, v));
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    int V, E;
    int u, v, w;

    cin >> V >> E;

    vector<vector<pair<int, int>>> graph(V);
    vector<int> dist(V, INF);
    vector<bool> visited(V, false);
    vector<int> path(V, -1);

    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(w, v));
        graph[v].push_back(make_pair(w, u));
    }

    prim(graph, dist, visited, path, 0);

    cout << printDist(dist);
    cout << endl;
    printEdges(path, dist);

    return 0;
}