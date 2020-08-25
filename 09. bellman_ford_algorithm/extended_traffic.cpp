 
// Solution: 1074 - Extended Traffic
// Link: http://lightoj.com/volume_showproblem.php?problem=1074

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

const int INF = 1e9;

struct Edge {
    int source;
    int target;
    int weight;
};

void bellman_ford(vector<Edge> &graph, vector<int> &dist, int source) {
    int V = dist.size() - 1;
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
            if (dist[u] != INF) {
                dist[v] = min(dist[u] + w, dist[v]);
            }
        }
    }
}

int main() {
    int T, n, m, q;
    int x;
    int u, v;

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> n;

        n = n + 1;
        vector<int> busyness(n, 0);
        
        for (int j = 1; j < n; j++)
        {
            cin >> x;
            busyness[j] = x;
        }
        
        cin >> m;

        vector<Edge> graph;
        vector<int> dist(n, INF);

        for (int j = 0; j < m; j++)
        {
            cin >> u >> v;
            int w = pow(busyness[v] - busyness[u], 3);
            graph.push_back(Edge{u, v, w});
        }

        int source = 1;
        int destination;
        bellman_ford(graph, dist, source);

        cin >> q;
        cout << "Case " << i + 1 << ":" << endl;
        for (int j = 0; j < q; j++)
        {
            cin >> destination;

            if (dist[destination] >= 3 && dist[destination] != INF) {
                cout << dist[destination];
            } else {
                cout << "?";
            }
            cout << endl;
        }
    }

    return 0;
}