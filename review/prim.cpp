#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void prim(const vector<vector<pair<int, int>>> &graph, vector<int> &dist, vector<int> &path, vector<bool> &visited, int source) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push(make_pair(0, source));
    dist[source] = 0;

    while (!pq.empty())
    {
        pair<int ,int> top = pq.top();
        pq.pop();

        int u = top.second;

        visited[u] = true;

        for (int i = 0; i < graph[u].size(); i++)
        {
            pair<int, int> neig = graph[u][i];
            int v = neig.second;
            int v_w = neig.first;

            if (!visited[v] && v_w < dist[v]) {
                dist[v] = v_w;
                path[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

void printMST(const vector<int> &path) {
    for (int i = 0; i < path.size(); i++)
    {
        if (path[i] != -1) {
            cout << i << " - " << path[i] << endl;
        }
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
    vector<bool> visited(V, false);

    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(w, v)); 
        graph[v].push_back(make_pair(w, u)); 
    }

    prim(graph, dist, path, visited, 0);
    printMST(path);

    int sum = 0;
    for (int i = 0; i < dist.size(); i++)
    {
        if (dist[i] != INF) {
            sum += dist[i];
        }
    }

    cout << sum;
    

    return 0;
}