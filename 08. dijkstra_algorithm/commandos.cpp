 
// Problem: 1174 - Commandos
// Link: http://lightoj.com/volume_showproblem.php?problem=1174

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
    int T, N, R;
    int u, v;
    int s, d;

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N >> R;

        vector<vector<pair<int, int>>> graph(N);
        vector<int> distS(N, INF);
        vector<int> distD(N, INF);

        for (int j = 0; j < R; j++)
        {
            cin >> u >> v;
            graph[u].push_back(make_pair(1, v));
            graph[v].push_back(make_pair(1, u));
        }
        
        cin >> s >> d;

        dijkstra(graph, distS, s);
        dijkstra(graph, distD, d);

        int max_val = 0;
        for (int j = 0; j < N; j++)
        {
            max_val = max(max_val, distS[j] + distD[j]);
        }
        

        cout << "Case " << i + 1 <<": " << max_val << endl;
    }

    return 0;
}