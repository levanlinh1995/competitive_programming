#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>
using namespace std;

const double INF = numeric_limits<double>::min();

struct Edge {
    int source, target;
    double weight;
};

void bellman_ford(const vector<Edge> &graph, vector<double> &dist, const int &source) {
    int V = dist.size() - 1;
    dist[source] = 1.0;

    int u, v;
    double w;

    for (int i = 1; i <= V - 1; i++)
    {
        for(Edge edg : graph) {
            u = edg.source;
            v = edg.target;
            w = edg.weight;

            if (dist[u] > INF) {
                dist[v] = max(dist[v], dist[u] * w);
                dist[u] = max(dist[u], dist[v] * w);
            }
        }
    }
}

int main() {
    int n, m;
    int a, b, p;

    while (true)
    {
        cin >> n;
        if (n == 0) {
            break;
        }

        vector<Edge> graph;
        vector<double> dist(n + 1, INF);

        cin >> m;

        for (int i = 0; i < m; i++)
        {
            cin >> a >> b >> p;
            graph.push_back(Edge{a, b, (double) p/100});
            graph.push_back(Edge{b, a, (double) p/100});
        }

        bellman_ford(graph, dist, 1);

        cout << fixed << setprecision(6) << dist[n] * 100.0 << " percent"  << endl;
    }

    return 0;
}