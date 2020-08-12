#include <bits/stdc++.h>
using namespace std;

const int INF = INT32_MAX;

void MST(const vector<vector<pair<int, int>>> &graph, vector<int> &dist, vector<bool> &visited, vector<int> &path, int source) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, source));

    while (!pq.empty())
    {
        pair<int, int> top = pq.top();
        pq.pop();
        int u = top.second;
        visited[u] = true;

        for (int i = 0; i < graph[u].size(); i++)
        {
            pair<int, int> neig = graph[u][i];
            int v = neig.second;
            int w = neig.first;

            if (!visited[v] && dist[v] > w) {
                dist[v] = w;
                pq.push(make_pair(w, v));
                path[v] = u;
            }
        }
    }
}

int calculateMinDistance(const vector<int> &dist) {
    int sum = 0;
    for (int i = 0; i < dist.size(); i++)
    {
        if (dist[i] != INF) {
            sum += dist[i];
        }
    }
    
    return sum;
}

int main() {
    freopen("input.txt", "r", stdin);

    int t, p, n, m;
    int a, b, c;

    cin >> t;

    while (t--)
    {
        cin >> p >> n >> m;

        int V = n + 1;
        vector<vector<pair<int, int>>> graph(V);
        vector<int> dist(V, INF);
        vector<int> path(V, -1);
        vector<bool> visited(V, false);

        while (m--)
        {
            cin >> a >> b >> c;

            graph[a].push_back(make_pair(c, b));
            graph[b].push_back(make_pair(c, a));
        }
        
        MST(graph, dist, visited, path, 1);

        cout << calculateMinDistance(dist) * p << endl;
    }
    

    return 0;
}