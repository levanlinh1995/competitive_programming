#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

double calculateDistance(const vector<pair<int, int>> &buildings, int i, int j) {
    int x1 = buildings[i].first;
    int y1 = buildings[i].second;
    int x2 = buildings[j].first;
    int y2 = buildings[j].second;

    return sqrt((x2 - x1)*(x2-x1) + (y2 - y1)*(y2 - y1));
}

double printDist(const vector<double> &dist) {
    double sum = 0.0;
    for (int i = 1; i < dist.size(); i++)
    {
        if (dist[i] != INF) {
            sum+= dist[i];
        }
    }
    return sum;
}

void prim(const vector<vector<pair<double, int>>> &graph, vector<double> &dist, vector<bool> &visited, int source) {
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;

    pq.push(make_pair(0.0, source));
    dist[source] = 0;

    while (!pq.empty())
    {
        pair<double, int> top = pq.top();
        pq.pop();
        int u = top.second;
        visited[u] = true;

        for (int i = 0; i < graph[u].size(); i++)
        {
            pair<double, int> neib = graph[u][i];
            int v = neib.second;
            double w = neib.first;

            if (!visited[v] && dist[v] > w) {
                dist[v] = w;
                pq.push(make_pair(w, v));
            }
        }
    }
}

int main() {

    freopen("input.txt", "r", stdin);
    int N, M;
    int x, y;
    int u, v;

    while (cin >> N)
    {
        int V = N + 1;

        vector<pair<int, int>> buildings(V);  // store coordinate of buildings
        vector<vector<pair<double, int>>> graph(V);
        vector<vector<int>> existingCables(V);
        vector<double> dist (V, INF);
        vector<bool> visited(V, false);

        for (int i = 1; i < V; i++)
        {
            cin >> x >> y;
            buildings[i] = make_pair(x, y);
        }

        for (int i = 1; i < V; i++)
        {
            for (int j = 1; j < V; j++)
            {
                if (i != j) {
                    double w = calculateDistance(buildings, i, j);
                    graph[i].push_back(make_pair(w, j));
                    graph[j].push_back(make_pair(w, i));
                }
            }
        }

        cin >> M;

        for (int i = 0; i < M; i++)
        {
            cin >> u >> v;
            graph[v].push_back(make_pair(0.0, u));
            graph[u].push_back(make_pair(0.0, v));
        }

        prim(graph, dist, visited, 1);

        cout << fixed << setprecision(2);
        cout << printDist(dist) << endl;
    }
    
    return 0;
}