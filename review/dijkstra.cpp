#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void dijkstra(const vector<vector<pair<int, int>>> &graph, vector<int> &dist, vector<int> &path, int source) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push(make_pair(0, source));
    dist[source] = 0;

    while (!pq.empty())
    {
        pair<int ,int> top = pq.top();
        pq.pop();

        int u = top.second;
        int u_w = top.first;

        for (int i = 0; i < graph[u].size(); i++)
        {
            pair<int, int> neig = graph[u][i];
            int v = neig.second;
            int v_w = neig.first;

            if (u_w + v_w < dist[v]) {
                dist[v] = u_w + v_w;
                path[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

void printPath(const vector<int> &path, int source, int end) {
    if (source == end) {
        cout << source;
        return;
    }

    if (path[end] == -1) {
        cout << "No found path";
        return;
    }

    vector<int> result;
    int f = end;
    result.push_back(f);

    while (true)
    {
        f = path[f];

        if (f == -1) {
            break;
        }

        result.push_back(f);

        if (f == source) {
            break;
        }
    }

    for (int i = result.size() -1; i >= 0; i--)
    {
        cout << result[i] << " ";
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    int V, E;
    int u, v, w;

    cin >> V >> E;

    vector<vector<pair<int, int>>> graph(V);
    vector<int> path(V, -1);
    vector<int> dist(V, INF);

    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(w, v)); 
    }

    dijkstra(graph, dist, path, 0);
    printPath(path, 0, 4);

    cout << endl << dist[4];

    return 0;
}