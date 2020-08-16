#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::min();

struct Edge {
    int source, target;
};

bool hasPathBFS(const vector<Edge> &graph, vector<bool> &visited, const int &source, const int &target) {
    fill(visited.begin(), visited.begin() + visited.size(), false);

    queue<int> q;
    q.push(source);
    visited[source] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (Edge edg : graph)
        {
            if (edg.source == u) {
                int v = edg.target;

                if (!visited[v]) {
                    q.push(v);
                    visited[v] = true;

                    if (v == target) {
                        return true;
                    }
                }
            }
        }
        
    }

    return false;
    
}


bool bellman_ford(const vector<Edge> &graph, vector<int> &dist,const vector<int> &energys, vector<bool> &visited, const int &source) {
    int V = dist.size() - 1;

    dist[source] = 100;

    int u, v, w;

    for (int i = 1; i <= V - 1; i++)
    {
        for (Edge edg : graph)
        {
            u = edg.source;
            v = edg.target;
            w = energys[v];

            if (dist[u] > 0) {
                dist[v] = max(dist[v], dist[u] + w);
            }
        }
    }

    for (Edge edg : graph)
    {
        u = edg.source;
        v = edg.target;
        w = energys[v];

        if (dist[u] > 0 && dist[u] + w > dist[v] && hasPathBFS(graph, visited, u, V)) {
            return true;
        }
    }

    return dist[V] > 0;
}

int main() {
    int n, energy, doorway, reachable_room;

    while (true)
    {
        cin >> n;
        if (n == -1) {
            break;
        }

        vector<Edge> graph;
        vector<int> dist(n + 1, INF);
        vector<int> energys(n + 1, 0);
        vector<bool> visited(n + 1, false);

        for (int i = 1; i <= n; i++)
        {
            cin >> energy >> doorway;
            energys[i] = energy;
            for (int j = 0; j < doorway; j++)
            {
                cin >> reachable_room;
                graph.push_back(Edge{i, reachable_room});
            }
        }

        bool res = bellman_ford(graph, dist, energys, visited, 1);

        if (res) {
            cout << "winnable";
        } else {
            cout << "hopeless";
        }
        cout << endl;
    }
    
    return 0;
}