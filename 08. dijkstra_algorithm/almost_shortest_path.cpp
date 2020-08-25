// Link: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3296

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = INT32_MAX;

void dijkstra(vector<vector<pair<int, int>>> &graph, vector<int> &dist, int start) {
    priority_queue<pair<int, int >, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(0, start));
    dist[start] = 0;

    while (!q.empty())
    {
        pair<int, int> top = q.top();
        q.pop();

        int u = top.second;
        int w = top.first;

        for (auto it = graph[u].begin(); it != graph[u].end(); ++it)
        {
            pair<int, int> neib = *it;

            if (w + neib.first < dist[neib.second]) {
                dist[neib.second] = w + neib.first;
                q.push(make_pair(w + neib.first, neib.second));
            }
        }
    }
}

void reset_dist(vector<int> &dist) {
    for (int i = 0; i < dist.size(); i++)
    {
        dist[i] = INF;
    }
}

int main() {
    int M, N;
    int S, D;
    int U, V, P;
    while (1)
    {
        cin >> N >> M;

        if (M == 0 && N == 0) {
            break;
        }

        cin >> S >> D;

        vector<vector<pair<int, int>>> graph(N);
        vector<vector<pair<int, int>>> graph1(N);
        vector<int> distS(N, INF);
        vector<int> distD(N, INF);


        for (int i = 0; i < M; i++)
        {
            cin >> U >> V >> P;
            graph[U].push_back(make_pair(P, V));
            graph1[V].push_back(make_pair(P, U));
        }

        dijkstra(graph, distS, S);
        dijkstra(graph1, distD, D);


        int min_length = distS[D];
        if (min_length == INF) {
            cout << -1 << endl;
            continue;
        }

        vector<vector<pair<int, int>>> new_graph(N);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < graph[i].size(); j++)
            {
                pair<int, int> edge = graph[i][j];
                int u = i;
                int v = edge.second;
                int w = edge.first;
                if (distS[u] + w + distD[v] != min_length) {
                    new_graph[u].push_back(make_pair(w, v));
                }
            }
        }

        reset_dist(distS);
        dijkstra(new_graph, distS, S);

        if (distS[D] == INF) {
            cout << -1 << endl;
            continue;
        } else {
            cout << distS[D] << endl;
        }
    }

    return 0;
}