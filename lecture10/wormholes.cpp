#include <vector>
#include <iostream>
using namespace std;

const int INF = 1e9;
struct Edge {
    int source;
    int target;
    int weight;
};

bool bellman_ford(vector<Edge> &graph, vector<int> &dist, int source) {
    int E = graph.size();
    int V = dist.size();

    int u, v, w;

    dist[source] = 0;

    for (int i = 1; i <= V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            u = graph[j].source;
            v = graph[j].target;
            w = graph[j].weight;

            if (dist[u] != INF && dist[u] + w < dist[v] ) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int j = 0; j < E; j++)
    {
        u = graph[j].source;
        v = graph[j].target;
        w = graph[j].weight;

        if (dist[u] != INF && dist[u] + w < dist[v] ) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int c, n, m;
    int x, y, t;

    cin >> c;

    for (int i = 0; i < c; i++)
    {
        cin >> n >> m;

        vector<int> dist(n, INF);
        vector<Edge> graph;

        for (int j = 0; j < m; j++)
        {
            cin >> x >> y >> t;
            graph.push_back(Edge{x, y, t});
        }

        int source = 0;
        bool res = bellman_ford(graph, dist, source);

        if (res) {
            cout << "not possible";
        } else {
            cout << "possible";
        }

        cout << endl;
        
    }
     

    return 0;
}