// Problem: 10986 - Sending email
// Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1927

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = INT32_MAX;

struct option {
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    }
};

void dijkstra(vector<vector<pair<int, int>>> &graph, vector<int> &dist, int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, option> q;
    q.push(make_pair(start, 0));
    dist[start] = 0;

    while (!q.empty())
    {
        pair<int, int> top = q.top();
        q.pop();

        int u = top.first;
        int w = top.second;

        for (int i = 0; i < graph[u].size(); i++)
        {
            pair<int, int> v = graph[u][i];

            if (w + v.second < dist[v.first]) {
                dist[v.first] = w + v.second;
                q.push(make_pair(v.first, w + v.second));
            }
        }
    }
    
}


int main() {
    int Q, N, M, S, T;
    int x, y, l;

    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        cin >> N >> M >> S >> T;

        vector<vector<pair<int, int>>> graph(N, vector<pair<int, int>>());
        vector<int> dist(N, INF);

        for (int j = 0; j < M; j++)
        {
            cin >> x >> y >> l;
            graph[x].push_back(make_pair(y, l));
            graph[y].push_back(make_pair(x, l));
        }

        dijkstra(graph, dist, S);

        if (dist[T] == INF) {
            cout << "Case #" << i + 1 << ": unreachable" << endl;
        } else {
            cout << "Case #" << i + 1 << ": " << dist[T] << endl;
        }

        graph.clear();
        dist.clear();
    }
    

    return 0;
}