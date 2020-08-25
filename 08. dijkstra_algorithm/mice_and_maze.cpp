// Problem: MICEMAZE - Mice and Maze
// Link: https://www.spoj.com/problems/MICEMAZE/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct option
{
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    }
};


void dijkstra(vector<vector<pair<int, int>>> &graph, vector<int> &path, vector<int> &dist, int start) {
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
            pair<int , int> neib = graph[u][i];
            if (w + neib.second < dist[neib.first]) {
                dist[neib.first] = w + neib.second;
                q.push(make_pair(neib.first, w + neib.second));
                path[neib.first] = u;
            }
        }
    }
    
}

int main() {
    const int INF = INT32_MAX;
    int N, E, T, M, a, b, t;

    cin >> N >> E >> T >> M;

    N = N + 1;

    vector<vector<pair<int, int>>> graph(N, vector<pair<int, int>>());
    vector<int> path(N, -1);
    vector<int> dist(N, INF);

    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> t;
        graph[a].push_back(make_pair(b, t));
    }

    int result = 0;
    for (int i = 1; i < N; i++)
    {
        // i as source
        for (int j = 1; j < N; j++)
        {
            path[j] = -1;
            dist[j] = INF;
        }
        
        dijkstra(graph, path, dist, i);
        if (dist[E] <= T){
            result++;
        }
    }

    cout << result;

    return 0;
}