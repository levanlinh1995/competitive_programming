// Problem: Chocolate Journey
// Link: https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/successful-marathon-0691ec04/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = INT32_MAX;

void dijkstra(vector<vector<pair<int, int>>> &graph, vector<int> &dist, int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(0, start));
    dist[start] = 0;

    while (!q.empty())
    {
        pair<int, int> top = q.top();
        q.pop();

        int u = top.second;
        int w = top.first;

        for (int i = 0; i < graph[u].size(); i++)
        {
            pair<int, int> neib = graph[u][i];

            if (w + neib.first < dist[neib.second]) {
                dist[neib.second] = w + neib.first;
                q.push(make_pair(w + neib.first, neib.second));
            }
        }
        
    }
    
}

int main() {
    int N, M, k, x;
    int y;
    int u, v, d;
    int A, B;

    cin >> N >> M >> k >> x;

    vector<int> chocolcate_cities;
    for (int i = 0; i < k; i++)
    {
        cin >> y;
        chocolcate_cities.push_back(y);
    }

    N = N + 1;
    vector<vector<pair<int, int>>> graph(N);
    vector<int> distA(N, INF);
    vector<int> distB(N, INF);

    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> d;
        graph[u].push_back(make_pair(d, v));
        graph[v].push_back(make_pair(d, u));
    }

    cin >> A >> B;

    dijkstra(graph, distA, A);
    dijkstra(graph, distB, B);
    
    int min_val = INF;

    for(int r : chocolcate_cities) {
       min_val = min(min_val, distB[r] + distA[r]);
    }

    if (min_val <= x && min_val >= 0) {
        cout << min_val;
    } else {
        cout << -1;
    }
    
    return 0;
}